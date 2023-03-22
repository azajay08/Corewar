/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:27 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 17:05:27 by sam              ###   ########.fr       */
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
	new_carriage(&(vm->carriages), clone_carriage(carriage, vm, pos));
	vm->carriage_count++;
}
