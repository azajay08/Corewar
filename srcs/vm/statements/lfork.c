/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:35 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 17:05:22 by sam              ###   ########.fr       */
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
	new_carriage(&(vm->carriages), clone_carriage(carriage, vm, pos));
	vm->carriage_count++;
}
