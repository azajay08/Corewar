/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 16:58:02 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/09 16:58:18 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_processes(t_vm *vm)
{
	t_process	*temp_process;

	temp_process = vm->processes;
	while (temp_process)
	{
		if (!temp_process->executed)
		{
			ft_printf("ID: %d | Position: %d | Player: %s\n", \
			temp_process->id, temp_process->pos, temp_process->player->name);
		}
		temp_process = temp_process->next;
	}
}
