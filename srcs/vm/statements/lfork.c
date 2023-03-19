/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:35 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:10:52 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - The lfork statement makes a copy of the carriage.
* - And this copy is placed at the address of the first argument % IND_MOD.
*/
void	ft_lfork(t_carriage *carriage, t_vm *vm)
{
	int	pos;

	pos = carriage->pos + carriage->args[0].value;
	pos = mod_calculator(pos);
	new_carriage(&(vm->carriages), clone_carriage(carriage, pos));
}
