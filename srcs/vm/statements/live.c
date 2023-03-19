/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:37 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:11:47 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Live counts that carriage, which performs the live statement, is alive.
*/
void	ft_live(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{
	int	value;

	carriage->last_live_cycle = corewar->cycles;
	corewar->lives_this_period++;
	value = get_n_byte(4, vm->arena, (carriage->pos + 1) % MEM_SIZE);
	value *= -1;
	if (value > 0 && value <= vm->player_count)
		vm->latest_live = value;
}
