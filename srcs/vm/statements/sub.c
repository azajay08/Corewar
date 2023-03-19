/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:51 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 15:31:17 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_sub(t_carriage *carriage)
{
	int	value;

	value = carriage->registers[carriage->args[0].value - 1] \
			- carriage->registers[carriage->args[1].value - 1];
	carriage->registers[carriage->args[2].value - 1] = value;
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
