/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:48 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 15:27:56 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_sti(t_carriage *carriage, t_vm *vm)
{
	int	value_1;
	int	value_2;
	int	result;

	value_1 = fetch_value(carriage, &carriage->args[1]);
	value_2 = fetch_value(carriage, &carriage->args[2]);
	result = (value_1 + value_2) % IDX_MOD;
	write_n_byte(vm, result + carriage->pos, 3, \
				carriage->registers[carriage->args[0].value - 1]);
}
