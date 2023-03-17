/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lfork.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:35 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:14:02 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_lfork:
** -
*/
void	ft_lfork(t_carriage *carriage, t_vm *vm)
{
	int			pos;
	t_carriage	*new;

	pos = carriage->pos + carriage->args[0].value;
	pos = mod_calculator(pos);
	new_carriage(&(vm->carriages), clone_carriage(carriage, pos));
}
