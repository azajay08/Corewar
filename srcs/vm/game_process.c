/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/15 20:10:07 by egaliber         ###   ########.fr       */
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
** - Updates the process to contain the code at the given arena position.
** - Converts the op_code at the position into an integer. If this integer
**   correlates to one of the registry statements, the process grabs the cycles
**   until its execution from the op_table and stores it.
** - Initialises the argument array for later use with the statement.
*/
static void	apply_statement(t_vm *vm, t_process *process)
{
	int	byte_as_int;
	int	i;

	i = -1;
	byte_as_int = vm->arena[process->pos];
	// process->op_code = vm->arena[process->pos];
	if (DEBUG == true)
		ft_printf(" | %.2x : %3d", process->op_code, byte_as_int);
	if (byte_as_int >= 1 && byte_as_int <= 16)
	{
		process->op_code = byte_as_int;
		process->cycles_until_exec = g_op_tab[byte_as_int - 1].cycles;
		if (DEBUG == true)
			ft_printf(" | Cycles until execution: %2d", process->cycles_until_exec);
	}
	else
		process->pos = (process->pos + 1) % MEM_SIZE;  // do we move vm->process
	// while (++i < 3)
	// 	process->args[i] = 0;
}

/*
** execute_statement:
** - Executes the statement correlating to the op code at the arena position.
*/
void	count_bytes_to_skip(t_process *process)
{
	int	i;

	i = 0;
	process->bytes_to_next = 0; // DONT NEED IF RESET
	process->bytes_to_next += g_op_tab[process->op_code - 1].arg_type_code + 1;
	while (i < g_op_tab[process->op_code - 1].arg_num)
	{
		process->bytes_to_next +=
	}
}

static void	execute_statement(t_vm *vm, t_process *process, t_corewar *cw)
{
	int position;
	
	if (DEBUG == true)
		ft_printf(" | Executing...");
	position = vm->arena[process->pos];
	if (position >= 1 && position <= 16)
	{
		process->op_code = position;
		process->result_code = (vm->arena[(process->pos + 1) % MEM_SIZE]);
		if (check_args_validity(&process))
		{
			if (reg_check(&process, &vm))
				get_arg_values(&process, &vm, &cw);
		}
		count_bytes_to_skip(&process); //calculate how much to move
		move_to_next_statement(process); //need to move player to next
	}
	else
		process->pos = (process->pos + 1) % MEM_SIZE; // do we move vm->process
	// process->executed = true;
	// vm->process_count--;
}

/*
** execute_cycle:
** - Performs the necessary actions for each game cycle.
*/
void	execute_cycle(t_vm *vm, t_corewar *corewar)
{
	t_process	*temp_process;

	if (DEBUG == true)
		ft_printf("%sCycle %d%s\n", URED, corewar->cycles, RESET);
	temp_process = vm->processes;
	while (temp_process)
	{
		if (!temp_process->executed)
		{
			if (DEBUG == true)
				ft_printf("Process %d | Position %4d | Player: %1d", \
				temp_process->id, temp_process->pos, temp_process->player->id);
			if (temp_process->cycles_until_exec == 0 && !temp_process->executed)
				apply_statement(vm, temp_process);
			if (temp_process->cycles_until_exec > 0 && !temp_process->executed)
				temp_process->cycles_until_exec--;
			if (temp_process->cycles_until_exec == 0 && !temp_process->executed)
				execute_statement(&vm, &temp_process, &corewar);
			if (DEBUG == true)
				ft_printf("\n");
		}
		temp_process = temp_process->next;
	}
	corewar->cycles++;
}

/*
** game_process:
** - Loops until only one player remains active in the arena.
*/
void	game_process(t_vm *vm)
{
	t_corewar	corewar;

	init_corewar(&corewar);
	init_arena(vm);
	vm->latest_live = vm->player_count;
	vm->cycle_dump = 0; // temporary until parsing is fixed to take flags.
	while (vm->processes != NULL && vm->process_count > 0)
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
