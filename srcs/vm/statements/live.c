/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:37 by sam               #+#    #+#             */
/*   Updated: 2023/03/13 23:23:31 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_live:
** -
*/

void	ft_live(t_process *process, t_corewar *corewar, t_vm *vm)
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
