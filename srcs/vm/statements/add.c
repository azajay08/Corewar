/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:46:32 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 16:33:06 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Sets the value of the third argument as argument1 + argument2.
*/
void	ft_add(t_carriage *carriage)
{
	uint8_t value;

	value = carriage->registers[carriage->args[0].value - 1] + \
		carriage->registers[carriage->args[1].value - 1];
	carriage->registers[carriage->args[2].value - 1] = value;
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
