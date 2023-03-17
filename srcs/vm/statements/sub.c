/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:51 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 16:34:46 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_sub(t_carriage *carriage)
{
	uint8_t value;

	value = carriage->registers[carriage->args[0].value - 1] - carriage->registers[carriage->args[1].value - 1];
	carriage->registers[carriage->args[2].value] - 1 = value;
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
