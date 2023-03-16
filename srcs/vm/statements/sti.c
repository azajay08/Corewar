/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:48 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_sti:
** -
*/

void	ft_sti(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{
    uint8_t value_1;
    uint8_t value_2;
    uint8_t result;

    value_1 = get_arg_value(carriage, carriage->args[1]);
    value_2 = get_arg_value(carriage, carriage->args[2]);
    result = (value_1 + value_2) % IDX_MOD;
    write_n_byte(vm->arena, result + carriage->pos, 4, carriage->registers[carriage->args[0].value]);
}
