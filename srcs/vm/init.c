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
** -
*/
void	init_vm(t_vm *vm)
{
	vm->player_count = 0;
	vm->checks = 0;
	vm->cycle = 0;
	vm->cycles_to_die = CYCLE_TO_DIE;
	vm->latest_live = 0;
	vm->process_count = 0;
	vm->total_processes = 0;
	vm->processes = NULL;
}

/*
** init_players:
** -
*/
void	init_players(t_vm *vm, unsigned int player_count)
{
	unsigned int	i;

	i = 0;
	while (++i < player_count)
		vm->player[i]->id = 0;
}
