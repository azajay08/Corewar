/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:42 by sam               #+#    #+#             */
/*   Updated: 2023/03/24 02:55:20 by ajones           ###   ########.fr       */
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
	int	value_1;
	int	value_2;
	int	temp;
	int	result;

	if (carriage->args[0].type == T_IND)
		value_1 = read_bytes(carriage->pos + carriage->args[0].value % \
			IDX_MOD, vm, 4);
	else
		value_1 = fetch_value(carriage, &carriage->args[0]);
	value_2 = fetch_value(carriage, &carriage->args[1]);
	temp = carriage->pos + (value_1 + value_2);
	temp = mod_calculator(temp);
	result = \
		read_bytes(temp, vm, 4);
	carriage->registers[carriage->args[2].value - 1] = result;
	if (result == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
