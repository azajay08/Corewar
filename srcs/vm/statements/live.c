/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:37 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:56:27 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_live(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{
	uint8_t value;

	carriage->last_live_cycle = corewar->cycles;
	corewar->lives_this_period++;
	value = get_n_byte(4, vm->arena, (carriage->pos  + 1) % MEM_SIZE);
	value *= -1;
	if (value > 0 && value <= vm->player_count)
		vm->latest_live = value;
	carriage->pos = (carriage->pos + 5) % MEM_SIZE;
}
