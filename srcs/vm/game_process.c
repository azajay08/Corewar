/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/21 18:09:09 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Initialises the data to be used within the Corewar game.
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
* - Performs the necessary actions for each game cycle.
* - Loops through the list of carriages, executing their process if their
*   execution countdown reaches zero.
*/
void	execute_cycle(t_vm *vm, t_corewar *corewar)
{
	t_carriage	*carriage;

	if (vm->b_flag == true)
		ft_printf("%sCycle %d:%s\n", URED, corewar->cycles, RESET);
	carriage = vm->carriages;
	while (carriage)
	{
		if (!carriage->dead)
		{
			if (vm->b_flag == true)
				ft_printf("Carriage %d (P%d): Position %4d ", \
				carriage->id, carriage->player->id, carriage->pos);
			if (carriage->cycles_until_exec == 0)
				apply_statement(vm, carriage);
			if (carriage->cycles_until_exec > 0)
				carriage->cycles_until_exec--;
			if (vm->b_flag == true)
				ft_printf(" | %.2x : %3d | Countdown: %d", carriage->op_code, \
				(int)vm->arena[carriage->pos], carriage->cycles_until_exec);
			if (carriage->cycles_until_exec == 0)
				execute_statement(vm, carriage, corewar);
			if (vm->b_flag == true)
				ft_printf("\n");
		}
		carriage = carriage->next;
	}
	corewar->cycles++;
	corewar->cycles_since_check++;
}

/*
* - Announces the winner after the game is over.
*/
static void	announce_winner(t_vm *vm)
{
	ft_printf("Contestant %d, \"%s\", has won !\n",
		vm->latest_live, vm->player[vm->latest_live]->name);
}

/*
* - Loops until only one player remains active in the arena.
* - If -d or -dump flag were used, the game will end at the given cycle and
*   print the arena.
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
		if (corewar.cycles_to_die <= 0 || \
			corewar.cycles_since_check == corewar.cycles_to_die)
			cycle_check(vm, &corewar);
	}
	announce_winner(vm);
}
