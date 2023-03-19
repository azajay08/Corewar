/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_values.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 18:08:35 by egaliber          #+#    #+#             */
/*   Updated: 2023/03/19 15:04:24 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
static int	get_dir_value(t_carriage *carriage, t_vm *vm, int offset)
{
	int	dir;

	dir = 0;
	if (g_op_tab[carriage->op_code - 1].size_t_dir == 4)
	{
		dir += vm->arena[(carriage->pos + offset) % MEM_SIZE] * 256 * 256 * 256;
		dir += vm->arena[(carriage->pos + offset + 1) % MEM_SIZE] * 256 * 256;
		dir += vm->arena[(carriage->pos + offset + 2) % MEM_SIZE] * 256;
		dir += vm->arena[(carriage->pos + offset + 3) % MEM_SIZE];
	}
	else
	{
		dir += vm->arena[(carriage->pos + offset) % MEM_SIZE] * 256;
		dir += vm->arena[(carriage->pos + offset + 1) % MEM_SIZE];
	}
	return (dir);
}

/*
* -
*/
static int	get_ind_value(t_carriage *carriage, t_vm *vm, int offset)
{
	int	ind;

	ind = 0;
	ind += vm->arena[(carriage->pos + offset) % MEM_SIZE] * 256;
	ind += vm->arena[(carriage->pos + offset + 1) % MEM_SIZE];
	return (ind);
}

/*
* -
*/
static int	get_reg_value(t_carriage *carriage, t_vm *vm, int offset)
{
	int	reg;

	reg = vm->arena[(carriage->pos + offset) % MEM_SIZE];
	return (reg);
}

/*
* -
*/
void	get_arg_values(t_carriage *carriage, t_vm *vm, t_corewar *cw)
{
	int	i;
	int	offset;
	int	byte_skip;

	i = 0;
	offset = g_op_tab[carriage->op_code - 1].arg_type_code + 1;
	while (i < g_op_tab[carriage->op_code - 1].arg_num)
	{
		byte_skip = arg_byte_count(carriage, carriage->args[i].type);
		if (carriage->args[i].type == T_REG)
			carriage->args[i].value = get_reg_value(carriage, vm, offset);
		else if (carriage->args[i].type == T_IND)
			carriage->args[i].value = get_ind_value(carriage, vm, offset);
		else if (carriage->args[i].type == T_DIR)
			carriage->args[i].value = get_dir_value(carriage, vm, offset);
		i++;
		offset += byte_skip;
	}
	sort_state_8(carriage->op_code, carriage, cw, vm);
}
