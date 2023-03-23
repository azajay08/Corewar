/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:39 by sam               #+#    #+#             */
/*   Updated: 2023/03/23 13:08:39 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - This statement works the same as ld statement.
* - The difference is only it writes the value obtained from the first argument
* - to the registry passed as the second argument.
*/
void	ft_lld(t_carriage *carriage, t_vm *vm)
{
	int	value;

	if (carriage->args[0].type == T_IND)
		value = read_bytes(carriage->pos + carriage->args[0].value, vm, 2);
	else
		value = carriage->args[0].value;
	carriage->registers[carriage->args[1].value - 1] = value;
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
