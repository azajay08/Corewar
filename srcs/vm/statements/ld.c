/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:07:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Ld loads a value into a registry.
* - If its a direct value then the value is loaded.
* - If its an indirect value the bytes from the address will be loaded.
*/
void	ft_ld(t_carriage *carriage)
{
	if (carriage->args[0].type == T_IND)
		carriage->registers[carriage->args[1].value - 1] \
			= carriage->args[0].value % IDX_MOD;
	else
		carriage->registers[carriage->args[1].value - 1] \
			= carriage->args[0].value;
	if (carriage->args[0].value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
