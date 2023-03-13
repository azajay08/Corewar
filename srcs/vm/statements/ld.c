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

/*
Statement Code		Argument Type Code			Argument # 1		Argument # 2
1 byte				1 byte						2/4 bytes			1 byte
02					first 2 pairs of bits		(dir/ind)			register number
*/

void	ld(t_process *process, t_vm *vm)
{
	u_int8_t value;


	//process->args[0] = get_bits();
	if (process->args[0] & IND_CODE) //check if its indirect value
	{
		get_pos();
		get_n_byte(4, vm->arena, indirect_index);
	}
}
