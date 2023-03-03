/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:32:02 by sam               #+#    #+#             */
/*   Updated: 2023/03/03 12:16:31 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_corewar(t_corewar *corewar)
{
	corewar->cycles_total = 0;
	corewar->cycles = 0;
	corewar->cycle_to_die = CYCLE_TO_DIE;
	corewar->lives_this_round = 0;
	corewar->checks = 0;
	corewar->carry = 0;
}

void	game_process(t_vm *vm, t_player *players)
{
	t_corewar	corewar;

	corewar = NULL;
	init_corewar(&corewar);
	init_arena(vm);
	while (vm->process != NULL && vm->process_count > 0)
	{
		if (corewar.cycles == vm->cycle_dump)
		{
			print_arena(vm);
			exit(EXIT_FAILURE);)
		}
		//cycle
	}
}
