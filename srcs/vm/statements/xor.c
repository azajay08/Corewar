/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:53 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_xor:
** -
*/
void	ft_xor(t_carriage *carriage)
[
    uint8_t value_1;
    uint8_t value_2;
    uint8_t result;

    value_1 = fetch_value(carriage, carriage->args[0]);
    value_2 = fetch_value(carriage, carriage->args[1]);
    result = (value_1 ^ value_2);
    carriage->registers[carriage->args[2].value - 1] = result;
    if (result == 0)
        carriage->carry = 1;
    else
        carriage->carry = 0;
]
