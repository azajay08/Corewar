/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:48 by sam               #+#    #+#             */
/*   Updated: 2023/03/23 13:42:31 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - This statement writes the value of the registry.
* - passed as the first parameter to the address.
*/
void	ft_sti(t_carriage *carriage, t_vm *vm)
{
	int	value_1;
	int	value_2;
	int	result;

	if (carriage->args[1].type == T_IND)
	{
		if (vm->f_flag)
			value_1 = read_bytes(carriage->pos + carriage->args[1].value % IDX_MOD, vm, 4);
		else
			value_1 = read_bytes(carriage->pos + carriage->args[1].value % IDX_MOD, vm, 2);
	}
	else
		value_1 = fetch_value(carriage, &carriage->args[1]);
	value_2 = fetch_value(carriage, &carriage->args[2]);
	result = (value_1 + value_2) % IDX_MOD;
	result = mod_calculator((carriage->pos + result));
	write_n_byte(vm, result, 3, \
				carriage->registers[carriage->args[0].value - 1]);
	if (vm->b_flag)
		ft_printf("args[0]type = |%d|  REG|%d| value is = |%d| was written to pos = |%d|", carriage->args[0].type, carriage->args[0].value, carriage->registers[15], result);
}
