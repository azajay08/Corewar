/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:09:20 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 16:36:34 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** byte_to_int:
** - Takes the value of the given position in the arena, casting it as an int
**   so that it can be used to find which statement to execute.
*/
int	byte_to_int(uint8_t *arena, int position)
{
	return ((int)arena[position]);
}

void	count_bytes_to_skip(t_carriage *carriage)
{
	int	i;

	i = 0;
	carriage->bytes_to_next = 0;
	carriage->bytes_to_next += g_op_tab[carriage->op_code - 1].arg_type_code + 1;
	while (i < g_op_tab[carriage->op_code - 1].arg_num)
	{
		if (carriage->args[i].type == T_REG)
			carriage->bytes_to_next += 1;
		else if (carriage->args[i].type == T_IND)
			carriage->bytes_to_next += 2;
		else
			carriage->bytes_to_next += g_op_tab[carriage->op_code - 1].size_t_dir;
		i++;
	}
}

void	move_to_next_statement(t_carriage *carriage)
{
	if (carriage->op_code == 9 && carriage->carry == 1)
	{
		carriage->bytes_to_next = 0;
		reset_args(carriage);
		return ;
	}
	carriage->pos = (carriage->pos + carriage->bytes_to_next) % MEM_SIZE;
	carriage->bytes_to_next = 0;
	reset_args(carriage);
}
