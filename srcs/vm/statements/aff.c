/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:46:54 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:03:07 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Takes a value from a registry that was passed as a single argument.
* - Converts it to type char. And displays as an ASCII character.
* - Only if -a flag is on.
*/
void	ft_aff(t_carriage *carriage, t_vm *vm)
{
	int	reg;

	reg = carriage->registers[carriage->args[0].value - 1];
	reg %= 256;
	if (vm->a_flag)
		ft_printf("AFF: %c\n", (char)reg);
}
