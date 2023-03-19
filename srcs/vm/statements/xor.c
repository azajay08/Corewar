/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:53 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:21:00 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
/*
* - Xor is almost identical to the <and> statement.
* - Only difference is, "bitwise AND" is replaced by "bitwise exclusive OR".
*/
void	ft_xor(t_carriage *carriage)
{
	int	value_1;
	int	value_2;
	int	result;

	value_1 = fetch_value(carriage, &carriage->args[0]);
	value_2 = fetch_value(carriage, &carriage->args[1]);
	result = (value_1 ^ value_2);
	carriage->registers[carriage->args[2].value - 1] = result;
	if (result == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
