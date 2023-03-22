/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:51 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 00:53:09 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Sets the value of the third argument as argument1 - argument2.
*/
void	ft_sub(t_carriage *carriage)
{
	int	value;

	// ft_printf("\ncarriage: |%d|\n", carriage->id);
	// ft_printf("\nvalue of arg1: |%d|\n", carriage->args[0].value);
	// ft_printf("value of arg2: |%d|\n", carriage->args[1].value);
	// // ft_printf("type of arg1: |%d|\n", carriage->args[0].type);
	// // ft_printf("type of arg2: |%d|\n", carriage->args[1].type);
	// ft_printf("result_code: |%d|\n", carriage->result_code);
	// ft_printf("value of reg1: |%d|\n", carriage->registers[carriage->args[0].value]);
	// ft_printf("value of reg2: |%d|\n", carriage->registers[carriage->args[1].value]);
	value = carriage->registers[carriage->args[0].value - 1] \
			- carriage->registers[carriage->args[1].value - 1];
	// ft_printf("value of value: |%d|\n\n", value);
	carriage->registers[carriage->args[2].value - 1] = value;
	if (value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
