/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:58:02 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/21 14:11:17 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Prints the contents of the given line of memory in the arena.
* - Highlights the byte of it is the position of a carriage.
*/
void	debug_print_memory_line(t_vm *vm, int i, uint8_t octets)
{
	t_carriage	*temp_carriage;
	int			j;

	j = -1;
	while (++j < octets)
	{
		temp_carriage = vm->carriages;
		while (temp_carriage)
		{
			if (!temp_carriage->dead && temp_carriage->pos == i + j)
			{
				ft_printf("%s", REDB);
				break ;
			}
			temp_carriage = temp_carriage->next;
		}
		ft_printf("%.2x%s ", vm->arena[i + j], RESET);
	}
	ft_printf("\n");
}
