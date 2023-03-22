/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:50:04 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/21 19:45:27 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Initialises the necessary data for a carriage.
*/
t_carriage	*initialise_carriage(t_player *player, uint32_t pos)
{
	t_carriage		*new;
	static uint32_t	id;

	new = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (!new)
		exit_vm("Memory allocation failure in initialise_carriage.");
	new->player = player;
	new->id = ++id;
	new->pos = pos;
	new->carry = 0;
	new->cycles_until_exec = 0;
	new->dead = false;
	new->next = NULL;
	new->result_code = 0;
	new->registers[0] = id * -1;
	return (new);
}

/*
* - Adds a fresh carriage to the front of the carriage list.
*/
void	new_carriage(t_carriage **carriages, t_carriage *new_carriage)
{
	if (new_carriage)
		new_carriage->next = *carriages;
	*carriages = new_carriage;
}

/*
* - Creates the starting carriages for each player, placing them at the first
*   position of each player on the board.
*/
void	set_carriages(t_vm *vm)
{
	uint32_t	id;
	uint32_t	pos;

	id = 0;
	pos = 0;
	while (++id <= vm->player_count)
	{
		new_carriage(&(vm->carriages), \
			initialise_carriage(vm->player[id], pos));
		vm->carriage_count++;
		pos += MEM_SIZE / vm->player_count;
	}
}
