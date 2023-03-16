/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 17:21:54 by sam              ###   ########.fr       */
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
	corewar->lives_this_period = 0;
	corewar->checks = 0;
	corewar->carry = 0;
}

/*
** execute_cycle:
** - Performs the necessary actions for each game cycle.
*/
void	execute_cycle(t_vm *vm, t_corewar *corewar)
{
	t_carriage	*carriage;

	if (DEBUG == true)
		ft_printf("%sCycle %d%s\n", URED, corewar->cycles, RESET);
	carriage = vm->carriages;
	while (carriage)
	{
		if (!carriage->dead)
		{
			if (DEBUG == true)
				ft_printf("Carriage %d | Position %4d | Player: %1d", \
				carriage->id, carriage->pos, carriage->player->id);
			if (carriage->cycles_until_exec == 0)
				apply_statement(vm, carriage);
			if (carriage->cycles_until_exec > 0)
				carriage->cycles_until_exec--;
			if (carriage->cycles_until_exec == 0)
				execute_statement(vm, carriage, corewar);
			if (DEBUG == true)
				ft_printf("\n");
		}
		carriage = carriage->next;
	}
	corewar->cycles++;
	corewar->cycles_since_check++;
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
	while (vm->carriages != NULL && vm->carriage_count > 0)
	{
		if (corewar.cycles == vm->dump)
		{
			print_arena(vm);
			exit(EXIT_SUCCESS);
		}
		execute_cycle(vm, &corewar);
		corewar.cycles_to_die--;
		if (corewar.cycles_to_die <= 0 || \
			corewar.cycles_since_check == corewar.cycles_to_die)
			cycle_check(vm, &corewar);
	}
	if (DEBUG == true)
		ft_printf("%sGame ended.\n%s", UGRN, RESET);
}
