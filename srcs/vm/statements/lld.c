/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lld.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:39 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:13:15 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - This statement works the same as ld statement.
* - The difference is only it writes the value obtained from the first argument
* - to the registry passed as the second argument.
*/
void	ft_lld(t_carriage *carriage)
{
	carriage->registers[carriage->args[1].value - 1] = carriage->args[0].value;
	if (carriage->args[0].value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
