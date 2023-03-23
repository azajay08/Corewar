/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:33 by sam               #+#    #+#             */
/*   Updated: 2023/03/23 12:55:55 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Loads a value to the registry from an address on the arena.
*/
void	ft_ldi(t_carriage *carriage, t_vm *vm)
{
	int	value_1;
	int	value_2;
	int	result;

	if (carriage->args[0].type == T_IND)
		value_1 = read_bytes(carriage->pos + carriage->args[0].value % IDX_MOD, vm, 4);
	else
		value_1 = fetch_value(carriage, &carriage->args[0]);
	value_2 = fetch_value(carriage, &carriage->args[1]);
	result = (value_1 + value_2) % IDX_MOD;
	result = mod_calculator(carriage->pos + result);
	carriage->registers[carriage->args[2].value - 1] = \
		read_bytes(result, vm, 4);
}
