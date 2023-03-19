/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lldi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:42 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 15:30:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ft_lldi:
** -
*/
void	ft_lldi(t_carriage *carriage, t_vm *vm)
{
	int	value_1;
	int	value_2;
	int	result;

	value_1 = fetch_value(carriage, &carriage->args[0]);
	value_2 = fetch_value(carriage, &carriage->args[1]);
	result = get_n_byte(4, vm->arena, (value_1 + value_2));
	carriage->registers[carriage->args[2].value - 1] = result;
}
