/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:30:47 by tlahin            #+#    #+#             */
/*   Updated: 2023/02/15 15:30:49 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** init_vm:
** - Initialises the necessary data for use throughout the program.
*/
void	init_vm(t_vm *vm)
{
	vm->player_count = 0;
	vm->checks = 0;
	vm->cycle = 0;
	vm->dump = -1;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->latest_live = 0;
	vm->carriage_count = 0;
	vm->carriages = NULL;
}

/*
** init_players:
** - Initialises the id of each player to 0.
*/
void	init_players(t_vm *vm, unsigned int player_count)
{
	unsigned int	i;

	i = 0;
	while (++i < player_count)
		vm->player[i]->id = 0;
}
