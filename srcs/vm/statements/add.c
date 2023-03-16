/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:46:32 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 17:09:04 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ft_add:
** - Sets the value of the third argument as argument1 + argument2.
*/

void	ft_add(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{
    uint8_t value;

    value = carriage->registers[carriage->args[0].value] + carriage->registers[carriage->args[1].value];
    carriage->registers[carriage->args[2].value] = value;
    if (value == 0)
        carriage->carry = 1;
    else
        carriage->carry = 0;
}
