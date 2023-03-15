/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:50:04 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/15 17:46:59 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_process	*initialise_process(t_player *player, uint32_t pos)
{
	t_process		*new;
	static uint32_t	id;

	new = (t_process *)ft_memalloc(sizeof(t_process));
	if (!new)
		exit_vm("Memory allocation failure in initialise_process.");
	new->player = player;
	new->id = ++id;
	new->pos = pos;
	new->carry = 0;
	new->cycles_until_exec = 0;
	new->executed = false;
	new->next = NULL;
	new->result_code = 0;
	new->args[0].type = 0;
	new->args[0].value = 0;
	return (new);
}

void	new_process(t_process **processes, t_process *new_process)
{
	if (new_process)
		new_process->next = *processes;
	*processes = new_process;
}

void	set_processes(t_vm *vm)
{
	uint32_t	id;
	uint32_t	pos;

	id = 0;
	pos = 0;
	while (++id <= vm->player_count)
	{
		new_process(&(vm->processes), initialise_process(vm->player[id], pos));
		vm->process_count++;
		pos += MEM_SIZE / vm->player_count;
	}
}
