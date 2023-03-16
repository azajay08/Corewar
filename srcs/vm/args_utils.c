/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 19:37:51 by egaliber          #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	reset_args(t_carriage *carriage)
{
	int i;

	i = 0;
	while (i < g_op_tab[carriage->op_code -1].arg_num)
	{
		carriage->args[i].type = 0;
		carriage->args[i].value = 0;
		i++;
	}
}

int	arg_byte_count(t_carriage *carriage, int type)
{
	if (type == T_REG)
		return (T_REG);
	if (type == T_IND)
		return (2);
	if (type == T_DIR)
		return (g_op_tab[carriage->op_code - 1].size_t_dir);
}

int	reg_check(t_carriage *carriage, t_vm *vm)
{
	int	i;
	int offset;
	int	byte_skip;

	i = 0;
	offset = g_op_tab[carriage->op_code - 1].arg_type_code + 1;
	while (i < g_op_tab[carriage->op_code - 1].arg_num)
	{
		byte_skip = arg_byte_count(&carriage, carriage->args[i].type);
		if (carriage->args[i].type == T_REG)
		{
			if (!check_reg_validity(carriage, vm, offset))
				return (0);
		}
		i++;
		offset += byte_skip;
	}
	return (1);
}