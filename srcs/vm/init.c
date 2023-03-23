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
* - Initialises the necessary data for use throughout the program.
*/
void	init_vm(t_vm *vm)
{
	vm->player_count = 0;
	vm->dump = -1;
	vm->total_carriages = 0;
	vm->latest_live = 0;
	vm->carriage_count = 0;
	vm->a_flag = false;
	vm->b_flag = false;
	vm->f_flag = true;
	vm->carriages = NULL;
}

/*
* - Initialises the id of each player to 0.
*/
void	init_players(t_vm *vm, unsigned int player_count)
{
	unsigned int	i;

	i = 0;
	while (++i < player_count)
		vm->player[i - 1]->id = 0;
}
