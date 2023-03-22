/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:58:02 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/22 12:37:01 by sam              ###   ########.fr       */
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
	int			c_printed;

	j = -1;
	while (++j < octets)
	{
		c_printed = 0;
		temp_carriage = vm->carriages;
		while (temp_carriage)
		{
			if (!temp_carriage->dead && temp_carriage->pos == i + j)
			{
				ft_printf("%s%.2x%s", REDB, vm->arena[i + j], WHTB);
				c_printed = 1;
				break ;
			}
			temp_carriage = temp_carriage->next;
		}
		if (c_printed == 0)
			ft_printf("%s%.2x", WHTB, vm->arena[i + j]);
		if (j < octets - 1)
			ft_putchar(' ');
	}
	ft_printf("%s\n", RESET);
}
