/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:09:20 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 15:26:05 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	byte_to_int(uint8_t *arena, int position)
{
	return ((int)arena[position]);
}

void	count_bytes_to_skip(t_process *process)
{
	int	i;

	i = 0;
	process->bytes_to_next = 0;
	process->bytes_to_next += g_op_tab[process->op_code - 1].arg_type_code + 1;
	while (i < g_op_tab[process->op_code - 1].arg_num)
	{
		if (process->args[i].type == T_REG)
			process->bytes_to_next += 1;
		else if (process->args[i].type == T_IND)
			process->bytes_to_next += 2;
		else
			process->bytes_to_next += g_op_tab[process->op_code - 1].size_t_dir;
		i++;
	}
}

void	move_to_next_statement(t_process *process, t_vm *vm)
{
	if (process->op_code == 9 && process->carry == 1)
	{
		process->bytes_to_next = 0;
		reset_args(process);
		return ;
	}
	process->pos = (process->pos + process->bytes_to_next) % MEM_SIZE;
	process->bytes_to_next = 0;
	reset_args(process);
}