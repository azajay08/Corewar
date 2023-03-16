/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:23 by tlahin            #+#    #+#             */
/*   Updated: 2023/03/16 17:12:47 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

u_int16_t	get_pos(u_int16_t pos)
{
	if (pos < MEM_SIZE)
		return (pos);
	return (pos % MEM_SIZE);
}

int8_t	check_args(t_carriage *carriage)
{
	int			i;
	u_int8_t	bit_pair;

	if (g_op_tab[carriage->op_code].arg_type_code == 0)
		return (0);
	i = 0;
	while (i < g_op_tab[carriage->op_code].arg_num)
	{
		bit_pair = get_bit_pair(carriage->pos + 1, i);
		if (bit_pair != g_op_tab[carriage->op_code].arg_type[i])
			return (-1);
		i++;
	}
	return (0);
}

void	write_n_byte(unsigned char *arena, uint32_t index, uint32_t size, uint32_t data)
{
	index = get_pos(index);
	while (size)
	{
		arena[index] = (unsigned char *)data[size];
		size--;
		index--;
	}
}

int32_t get_arg_value(t_carriage *carriage, t_args *arg)
{
	if (arg->type == T_REG)
		return (carriage->registers[arg->value]);
	return (arg->value);
}
