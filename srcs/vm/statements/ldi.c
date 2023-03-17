/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ldi.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:33 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_ldi:
** -
*/

void	ft_ldi(t_carriage *carriage, t_vm *vm)
{
    uint8_t value_1;
    uint8_t value_2;
    uint8_t result;

    value_1 = fetch_value(carriage, carriage->args[0]);
    value_2 = fetch_value(carriage, carriage->args[1]);
    result = get_n_byte(4, vm->arena, ((value_1 + value_2) % IDX_MOD));
    carriage->registers[carriage->args[2].value] = result;
}
