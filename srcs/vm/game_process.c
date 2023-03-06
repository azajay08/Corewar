/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/06 14:44:29 by sam              ###   ########.fr       */
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
** execute_cycle:
** -
*/
void	execute_cycle(t_vm *vm, t_corewar *corewar)
{
	t_process	*temp_process;

	temp_process = vm->processes;
	corewar->cycles_total++;
	while (temp_process)
	{
		//apply statements
		//reduce cooldowns
		//execute statements
		temp_process = temp_process->next;
	}
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
	introduce_players(vm);
	ft_printf("Initiating game.\n");
	while (vm->processes != NULL && vm->process_count > 0)
	{
		if (corewar.cycles == vm->cycle_dump)
		{
			print_arena(vm);
			exit(EXIT_FAILURE);
		}
		execute_cycle(vm, &corewar);
	}
}
