/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:51 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 17:08:39 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ft_sub:
** -
*/

void	ft_sub(t_carriage *carriage)
{
    uint8_t value;

    value = carriage->registers[carriage->args[0].value] - carriage->registers[carriage->args[1].value];
    carriage->registers[carriage->args[2].value] = value;
    if (value == 0)
        carriage->carry = 1;
    else
        carriage->carry = 0;
}
