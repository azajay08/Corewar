/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:42 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 00:52:03 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Lldi works similarly to ldi.
* - The difference is when forming the address,
* - you shouldn't truncate by modulo IDX_MOD.
*/
void	ft_lldi(t_carriage *carriage, t_vm *vm)
{
	if (vm)
		ft_printf("");
	int	value_1;
	int	value_2;
	int	result;

	if (carriage->args[0].type == T_IND)
	{
		value_1 = read_bytes(carriage->pos + carriage->args[0].value % IDX_MOD, vm, 4);
	}
	else
		value_1 = fetch_value(carriage, &carriage->args[0]);
	value_1 = fetch_value(carriage, &carriage->args[0]);
	value_2 = fetch_value(carriage, &carriage->args[1]);
	result = carriage->pos + (value_1 + value_2);
	result = mod_calculator(result);
	carriage->registers[carriage->args[2].value - 1] = read_bytes(result, vm, 4);
}
