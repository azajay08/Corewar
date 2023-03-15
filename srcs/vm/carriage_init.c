/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriages.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:50:04 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/15 16:19:09 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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
	return (new);
}

void	new_carriage(t_carriage **carriages, t_carriage *new_carriage)
{
	if (new_carriage)
		new_carriage->next = *carriages;
	*carriages = new_carriage;
}

void	set_carriages(t_vm *vm)
{
	uint32_t	id;
	uint32_t	pos;

	id = 0;
	pos = 0;
	while (++id <= vm->player_count)
	{
		new_carriage(&(vm->carriages), initialise_carriage(vm->player[id], pos));
		vm->carriage_count++;
		pos += MEM_SIZE / vm->player_count;
	}
}
