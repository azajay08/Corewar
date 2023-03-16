/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:38:21 by sam               #+#    #+#             */
/*   Updated: 2023/03/15 17:43:25 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** check_carriages:
** - Checks each active carriage in the game. If the carriage has not used
**   a live statement since the previous cycles_to_die count, the carriage
**   is considered dead and no longer active.
*/
static void	check_carriages(t_vm *vm, t_corewar *corewar)
{
	t_carriage	*temp_carriage;

	temp_carriage = vm->carriages;
	while (temp_carriage)
	{
		if (!temp_carriage->dead)
		{
			if (corewar->cycles_to_die <= \
				corewar->cycles - temp_carriage->last_live_cycle)
			{
				temp_carriage->dead = true;
				vm->carriage_count--;
			}
		}
		temp_carriage = temp_carriage->next;
	}
}

/*
** check_lives:
** - If there have been 21 live statements used during this cycles_to_die
**   period, the cycles_to_die value is lowered by 50.
** - If the maximum amount of checks after the value of cycles_to_die does not
**   change, then it will be forcibly reduced by the value of CYCLE_DELTA.
*/
static void	check_lives(t_vm *vm, t_corewar *corewar)
{
	uint32_t	i;

	i = 0;
	if (corewar->lives_this_period >= NBR_LIVE || corewar->checks == MAX_CHECKS)
	{
		corewar->cycles_to_die -= CYCLE_DELTA;
		corewar->checks = 0;
	}
	while (++i <= vm->player_count)
		vm->player[i]->live_count = 0;
}

/*
** cycle_check:
** -
*/
void	cycle_check(t_vm *vm, t_corewar *corewar)
{
	corewar->cycles++;
	check_carriages(vm, corewar);
	check_lives(vm, corewar);
	corewar->lives_this_period = 0;
	corewar->cycles_since_check = 0;
}
