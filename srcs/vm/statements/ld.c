/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
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

void	ft_ld(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{

}
