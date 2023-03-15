/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:58:02 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/15 17:01:16 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** :
** - 
*/
void	print_carriages(t_vm *vm)
{
	t_carriage	*temp_carriage;

	temp_carriage = vm->carriages;
	while (temp_carriage)
	{
		if (!temp_carriage->dead)
		{
			ft_printf("ID: %d | Position: %d | Player: %s\n", \
			temp_carriage->id, temp_carriage->pos, temp_carriage->player->name);
		}
		temp_carriage = temp_carriage->next;
	}
}
