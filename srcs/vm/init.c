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

#include "../../includes/vm.h"

void	init_vm(t_vm *vm)
{
	vm->checks = 0;
	vm->cycle = 0;
	vm->cycle_to_die = CYCLE_TO_DIE;
	vm->latest_live = NULL;
	vm->player_count = 0;
	vm->process = NULL;
}

void	init_players(t_player *players, unsigned int player_count)
{
	unsigned int i;

	i = 1;
	while (i < player_count)
	{
		players[i].id = 0;
		i++;
	}
}
