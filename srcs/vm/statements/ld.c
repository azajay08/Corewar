/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 15:04:20 by sam              ###   ########.fr       */
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
	if (carriage || corewar || vm)
		ft_printf("");
}
