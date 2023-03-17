/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:46:54 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 17:14:03 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_aff(t_carriage *carriage, t_vm *vm)
{
	int	reg;

	reg = carriage->registers[carriage->args[0].value - 1];
	reg %= 256;
	if (vm->a_flag)
		ft_printf("AFF: %c\n", (char)reg);
}
