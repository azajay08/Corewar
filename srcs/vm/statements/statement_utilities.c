/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement_utilities.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:39:23 by tlahin            #+#    #+#             */
/*   Updated: 2023/03/22 17:08:35 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Clone the carriage that used fork or lfork.
*/
t_carriage	*clone_carriage(t_carriage *old, t_vm *vm, int pos)
{
	int			i;
	t_carriage	*new;

	new = (t_carriage *)ft_memalloc(sizeof(t_carriage));
	if (!new)
		exit_vm("Memory allocation failure in initialise_carriage.");
	new->player = old->player;
	new->id = ++vm->total_carriages;
	new->pos = pos;
	new->carry = old->carry;
	new->cycles_until_exec = 0;
	new->dead = false;
	new->next = NULL;
	new->result_code = 0;
	new->last_live_cycle = old->last_live_cycle;
	i = 0;
	while (i < REG_NUMBER)
	{
		new->registers[i] = old->registers[i];
		i++;
	}
	return (new);
}

/*
* - Calculates the correct position.
*/
int	mod_calculator(int pos)
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

/*
* - Rewrites N amount of bites to the arena.
*/
void	write_n_byte(t_vm *vm, int index, int size, int data)
{
	index = mod_calculator(index);
	while ((int)size >= 0)
	{
		vm->arena[index % MEM_SIZE] = ((unsigned char *)&data)[size];
		size--;
		index++;
	}
}

/*
* - Gets the inside a registry.
*/
int	fetch_value(t_carriage *carriage, t_args *arg)
{
	if (arg->type == T_REG)
		return (carriage->registers[arg->value - 1]);
	return (arg->value);
}

int	read_bytes(int pos, t_vm *vm, int n)
{
	int	result;

	result = 0;
	if (n == 4)
	{
		result += vm->arena[pos % MEM_SIZE] * 256 * 256 * 256;
		result += vm->arena[(pos + 1) % MEM_SIZE] * 256 * 256;
		result += vm->arena[(pos + 2) % MEM_SIZE] * 256;
		result += vm->arena[(pos + 3) % MEM_SIZE];
		return (result);
	}
	else
	{
		result += vm->arena[(pos) % MEM_SIZE] * 256;
		result += vm->arena[(pos + 1) % MEM_SIZE];
	}
	return (result);
}
