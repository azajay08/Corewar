/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:39 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 16:33:43 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_lld(t_carriage *carriage)
{
	carriage->registers[carriage->args[1].value - 1] = carriage->args[0].value;
	if (carriage->args[0].value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
