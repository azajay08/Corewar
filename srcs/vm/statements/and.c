/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   and.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:25 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 17:18:33 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Performs a "bitwise AND" statement for the values​of the first two arguments.
* - and writes the result to the registry passed as the third argument.
*/
void	ft_and(t_carriage *carriage, t_vm *vm)
{
	int	value_1;
	int	value_2;
	int	result;

	if (carriage->args[0].type == T_IND)
		value_1 = read_bytes(carriage->pos + carriage->args[0].value % \
			IDX_MOD, vm, 4);
	else
		value_1 = fetch_value(carriage, &carriage->args[0]);
	if (carriage->args[1].type == T_IND)
		value_2 = read_bytes(carriage->pos + carriage->args[1].value % \
			IDX_MOD, vm, 4);
	else
		value_2 = fetch_value(carriage, &carriage->args[1]);
	result = (value_1 & value_2);
	carriage->registers[carriage->args[2].value - 1] = result;
	if (result == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
