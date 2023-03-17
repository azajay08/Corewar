/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:23 by tlahin            #+#    #+#             */
/*   Updated: 2023/03/17 15:03:24 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int    mod_calculator(int pos)
{
    if (pos < 0)
    {
        pos %= MEM_SIZE;
        pos += MEM_SIZE;
    }
    else
        pos %= MEM_SIZE;
    return (pos);
}

void	write_n_byte(t_vm *vm, uint32_t index, uint32_t size, uint32_t data)
{
	index = mod_calculator(index);
	while (size >= 0)
	{
		vm->arena[index % MEM_SIZE] = (unsigned char *)data[size];
		size--;
		index++;
	}
}

int32_t fetch_value(t_carriage *carriage, t_args *arg)
{
	if (arg->type == T_REG)
		return (carriage->registers[arg->value]);
	return (arg->value);
}
