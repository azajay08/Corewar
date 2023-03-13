/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:37 by sam               #+#    #+#             */
/*   Updated: 2023/03/02 13:29:33 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_live:
** -
*/

void	live(t_process *process, t_corewar *corewar, t_vm *vm)
{
	int value;

	process->last_live_cycle = corewar->cycles;
	corewar->lives_this_round++;
	value = get_n_byte(4, vm->arena, (process->pos  + 1) % MEM_SIZE);
	value *= -1;
	if (value > 0 && value <= vm->player_count)
		vm->latest_live = value;
	process->pos = (process->pos + 5) % MEM_SIZE;
}
