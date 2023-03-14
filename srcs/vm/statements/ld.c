/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by sam               #+#    #+#             */
/*   Updated: 2023/03/02 13:29:45 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_ld:
** -
*/
void	ld(t_process *process)
{
	process->registers[process->args[1]] = process->args[0];
	if (process->args[0] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
