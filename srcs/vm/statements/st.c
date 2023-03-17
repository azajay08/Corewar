/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:46 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 17:13:38 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_st:
** -
*/

void	ft_st(t_carriage *carriage, t_vm *vm)
{
    if (carriage->args[1].type == T_REG)
        carriage->registers[carriage->args[1].value] = carriage->args[0].value;
    else if (carriage->args[1].type == T_IND)
        write_n_byte(vm, carriage->args[1].value, 4, carriage->registers[carriage->args[0].value]);
}
