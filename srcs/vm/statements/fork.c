/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:27 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:04:45 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Makes a copy of the given carriage, 
* - putting it onto the arena in the given placement.
*/
void	ft_fork(t_carriage *carriage, t_vm *vm)
{
	int			pos;

	pos = carriage->pos + carriage->args[0].value % IDX_MOD;
	pos = mod_calculator(pos);
	new_carriage(&(vm->carriages), clone_carriage(carriage, pos));
}
