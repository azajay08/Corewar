/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:05:11 by ajones            #+#    #+#             */
/*   Updated: 2023/03/16 15:39:41 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sort_state_8(int state, t_carriage *carriage, t_corewar *cw, t_vm *vm)
{
	if (state == LIVE)
		ft_live(carriage, cw, vm);
	else if (state == LD)
		ft_ld(carriage, cw, vm);
	else if (state == ST)
		ft_st(carriage, cw, vm);
	else if (state == ADD)
		ft_add(carriage, cw, vm);
	else if (state == SUB)
		ft_sub(carriage, cw, vm);
	else if (state == AND)
		ft_and(carriage, cw, vm);
	else if (state == OR)
		ft_or(carriage, cw, vm);
	else if (state == XOR)
		ft_xor(carriage, cw, vm);
	else
		sort_state_16(state, carriage, cw, vm);
}

void	sort_state_16(int state, t_carriage *carriage, t_corewar *cw, t_vm *vm)
{
	if (state == ZJMP)
		ft_zjmp(carriage, cw, vm);
	else if (state == LDI)
		ft_ldi(carriage, cw, vm);
	else if (state == STI)
		ft_sti(carriage, cw, vm);
	else if (state == FORK)
		ft_fork(carriage, cw, vm);
	else if (state == LLD)
		ft_lld(carriage, cw, vm);
	else if (state == LLDI)
		ft_lldi(carriage, cw, vm);
	else if (state == LFORK)
		ft_lfork(carriage, cw, vm);
	else if (state == AFF)
		ft_aff(carriage, cw, vm);
}