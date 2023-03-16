/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 15:02:47 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** init_corewar:
** - Initialises the data to be used within the Corewar game.
*/
void	init_corewar(t_corewar *corewar)
{
	corewar->cycles_total = 0;
	corewar->cycles = 0;
	corewar->cycles_to_die = CYCLE_TO_DIE;
	corewar->lives_this_round = 0;
	corewar->checks = 0;
	corewar->carry = 0;
}

/*
** apply_statement:
** - Updates the carriage to contain the code at the given arena position.
** - Converts the op_code at the position into an integer. If this integer
**   correlates to one of the registry statements, the carriage grabs the cycles
**   until its execution from the op_table and stores it.
** - Initialises the argument array for later use with the statement.
*/
static void	apply_statement(t_vm *vm, t_carriage *carriage)
{
	int	byte_as_int;
	int	i;

	i = -1;
	byte_as_int = vm->arena[carriage->pos];

	if (DEBUG == true)
		ft_printf(" | %.2x : %3d", carriage->op_code, byte_as_int);
	if (byte_as_int >= 1 && byte_as_int <= 16)
	{
		carriage->op_code = byte_as_int;
		carriage->cycles_until_exec = g_op_tab[byte_as_int - 1].cycles;
		if (DEBUG == true)
			ft_printf(" | Cycles until execution: %2d", carriage->cycles_until_exec);
	}
	else
		carriage->pos = (carriage->pos + 1) % MEM_SIZE;
}

/*
** execute_statement:
** - Executes the statement correlating to the op code at the arena position.
*/
static void	execute_statement(t_vm *vm, t_carriage *carriage, t_corewar *cw)
{
	int position;
	
	if (DEBUG == true)
		ft_printf(" | Executing...");
	position = vm->arena[carriage->pos];
	if (position >= 1 && position <= 16)
	{
		carriage->op_code = position;
		carriage->result_code = (vm->arena[(carriage->pos + 1) % MEM_SIZE]);
		if (check_args_validity(&carriage))
		{
			if (reg_check(&carriage, &vm))
				get_arg_values(&carriage, &vm, &cw);
		}
		count_bytes_to_skip(&carriage);
		move_to_next_statement(carriage, vm);
	}
	else
		carriage->pos = (carriage->pos + 1) % MEM_SIZE; // do we move vm->carriage
	// carriage->executed = true;
	// vm->carriage_count--;
}

/*
** execute_cycle:
** - Performs the necessary actions for each game cycle.
*/
void	execute_cycle(t_vm *vm, t_corewar *corewar)
{
	t_carriage	*temp_carriage;

	if (DEBUG == true)
		ft_printf("%sCycle %d%s\n", URED, corewar->cycles, RESET);
	temp_carriage = vm->carriages;
	while (temp_carriage)
	{
		if (!temp_carriage->dead)
		{
			if (DEBUG == true)
				ft_printf("carriage %d | Position %4d | Player: %1d", \
				temp_carriage->id, temp_carriage->pos, temp_carriage->player->id);
			if (temp_carriage->cycles_until_exec == 0 && !temp_carriage->dead)
				apply_statement(vm, temp_carriage);
			if (temp_carriage->cycles_until_exec > 0 && !temp_carriage->dead)
				temp_carriage->cycles_until_exec--;
			if (temp_carriage->cycles_until_exec == 0 && !temp_carriage->dead)
				execute_statement(&vm, &temp_carriage, &corewar);
			if (DEBUG == true)
				ft_printf("\n");
		}
		temp_carriage = temp_carriage->next;
	}
	corewar->cycles++;
}

/*
** game_carriage:
** - Loops until only one player remains active in the arena.
*/
void	game_process(t_vm *vm)
{
	t_corewar	corewar;

	init_corewar(&corewar);
	init_arena(vm);
	vm->latest_live = vm->player_count;
	vm->cycle_dump = 0; // temporary until parsing is fixed to take flags.
	while (vm->carriages != NULL && vm->carriage_count > 0)
	{
		if (corewar.cycles == vm->cycle_dump)
		{
			print_arena(vm);
			exit(EXIT_SUCCESS);
		}
		execute_cycle(vm, &corewar);
		if (vm->cycles_to_die <= 0)
			ft_printf("ended\n");
		else
			vm->cycles_to_die--;
	}
	if (DEBUG == true)
		ft_printf("%sGame ended.\n%s", UGRN, RESET);
}
