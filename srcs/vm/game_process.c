/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_carriage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/15 16:16:59 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** init_corewar:
** - Initialises the data to be used within the Corewar game.
*/
void	init_corewar(t_corewar *corewar)
{
	corewar->cycles = 0;
	corewar->cycles_since_check = 0;
	corewar->cycles_to_die = CYCLE_TO_DIE;
	corewar->lives_this_period= 0;
	corewar->checks = 0;
	corewar->carry = 0;
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
				ft_printf("Process %d | Position %4d | Player: %1d", \
				temp_carriage->id, temp_carriage->pos, temp_carriage->player->id);
			if (temp_carriage->cycles_until_exec == 0)
				apply_statement(vm, temp_carriage);
			if (temp_carriage->cycles_until_exec > 0)
				temp_carriage->cycles_until_exec--;
			if (temp_carriage->cycles_until_exec == 0)
				execute_statement(vm, temp_carriage);
			if (DEBUG == true)
				ft_printf("\n");
		}
		temp_carriage = temp_carriage->next;
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
	while (vm->carriages != NULL && vm->carriage_count > 0)
	{
		if (corewar.cycles == vm->cycle_dump)
		{
			print_arena(vm);
			exit(EXIT_SUCCESS);
		}
		execute_cycle(vm, &corewar);
		cycle_check(vm, &corewar);
	}
	if (DEBUG == true)
		ft_printf("%sGame ended.\n%s", UGRN, RESET);
}
