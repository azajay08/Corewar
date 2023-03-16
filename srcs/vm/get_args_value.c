/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:08:35 by egaliber          #+#    #+#             */
/*   Updated: 2023/03/15 20:03:17 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int	get_dir_value(t_process *process, t_vm *vm, int offset)
{
	int	dir;

	dir = 0;
	if (g_op_tab[process->op_code - 1].size_t_dir == 4)
	{
		dir += vm->arena[(process->pos + offset) % MEM_SIZE] * 256 * 256 * 256;
		dir += vm->arena[(process->pos + offset + 1) % MEM_SIZE] * 256 * 256;
		dir += vm->arena[(process->pos + offset + 2) % MEM_SIZE] * 256;
		dir += vm->arena[(process->pos + offset + 3) % MEM_SIZE];
	}
	else
	{
		dir += vm->arena[(process->pos + offset) % MEM_SIZE] * 256;
		dir += vm->arena[(process->pos + offset + 1) % MEM_SIZE];
	}
	return (dir);
}
int	get_ind_value(t_process *process, t_vm *vm, int offset)
{
	int	ind;

	ind = 0;
	ind += vm->arena[(process->pos + offset) % MEM_SIZE] * 256;
	ind += vm->arena[(process->pos + offset + 1) % MEM_SIZE];
	return (ind);
}

int	get_reg_value(t_process *process, t_vm *vm, int offset)
{
	int	reg;
	
	reg = vm->arena[(process->pos + offset) % MEM_SIZE];
	return (reg);
}

void	get_args_values(t_process *process, t_vm *vm, t_corewar *cw)
{
	int	i;
	int offset;
	int	byte_skip;

	i = 0;
	offset = g_op_tab[process->op_code - 1].arg_type_code + 1;
	while (i < g_op_tab[process->op_code - 1].arg_num)
	{
		byte_skip = arg_val(&process, process->args[i].type);
		if (process->args[i].type == T_REG)
			process->args[i].value = get_reg_value(process, vm, offset);
		else if (process->args[i].type == T_IND)
			process->args[i].value = get_ind_value(process, vm, offset);
		else if (process->args[i].type == T_DIR)
			process->args[i].value = get_dir_value(process, vm, offset);
		i++;
		offset += byte_skip;
	}
	sort_state_8(process->op_code, process, cw, vm);
	return (1);
}
