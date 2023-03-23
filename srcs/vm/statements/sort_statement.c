/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:05:11 by ajones            #+#    #+#             */
/*   Updated: 2023/03/22 22:56:28 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Picks the corresponding statement 9 - 16.
*/
void	sort_state_16(int state, t_carriage *carriage, t_vm *vm)
{
	if (state == ZJMP)
		ft_zjmp(carriage);
	else if (state == LDI)
		ft_ldi(carriage, vm);
	else if (state == STI)
		ft_sti(carriage, vm);
	else if (state == FORK)
		ft_fork(carriage, vm);
	else if (state == LLD)
		ft_lld(carriage, vm);
	else if (state == LLDI)
		ft_lldi(carriage, vm);
	else if (state == LFORK)
		ft_lfork(carriage, vm);
	else if (state == AFF)
		ft_aff(carriage, vm);
}

/*
* - Picks the corresponding statement 1 - 8. Or sends to sort_16.
*/
void	sort_state_8(int state, t_carriage *carriage, t_corewar *cw, t_vm *vm)
{
	if (state == LIVE)
		ft_live(carriage, cw, vm);
	else if (state == LD)
		ft_ld(carriage, vm);
	else if (state == ST)
		ft_st(carriage, vm);
	else if (state == ADD)
		ft_add(carriage);
	else if (state == SUB)
		ft_sub(carriage);
	else if (state == AND)
		ft_and(carriage, vm);
	else if (state == OR)
		ft_or(carriage, vm);
	else if (state == XOR)
		ft_xor(carriage, vm);
	else
		sort_state_16(state, carriage, vm);
}
