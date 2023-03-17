/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:32:03 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
Statement Code		Argument Type Code			Argument # 1		Argument # 2
1 byte				1 byte						2/4 bytes			1 byte
02					first 2 pairs of bits		(dir/ind)			register number
*/

/*
* -
*/
void	ft_ld(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{
	process->registers[process->args[1]] = process->args[0];
	if (process->args[0] == 0)
		process->carry = 1;
	else
		process->carry = 0;
}
