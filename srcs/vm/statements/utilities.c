/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:23 by tlahin            #+#    #+#             */
/*   Updated: 2023/03/13 12:39:25 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

u_int16_t get_pos(u_int16_t pos)
{
	if (pos < MEM_SIZE)
		return (pos);
	return (pos % MEM_SIZE);
}

//needed?
int8_t check_args(t_process *process)
{
	int	i;
	u_int8_t bit_pair;

	if (g_op_tab[process->op_code].arg_type_code == 0)
		return (0);
	i = 0;
	while(i < g_op_tab[process->op_code].arg_num)
	{
		bit_pair = get_bit_pair(process->pos + 1, i);
		if (bit_pair != g_op_tab[process->op_code].arg_type[i])
			return (-1);
		i++;
	}
	return (0);
}
