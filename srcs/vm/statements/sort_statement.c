/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   statement_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:05:11 by ajones            #+#    #+#             */
/*   Updated: 2023/03/13 23:18:12 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	sort_state_8(int state, t_process *process, t_corewar *cw, t_vm *vm)
{
	if (state == LIVE)
		ft_live(process, cw, vm);
	else if (state == LD)
		ft_ld(process, cw, vm);
	else if (state == ST)
		ft_st(process, cw, vm);
	else if (state == ADD)
		ft_add(process, cw, vm);
	else if (state == SUB)
		ft_sub(process, cw, vm);
	else if (state == AND)
		ft_and(process, cw, vm);
	else if (state == OR)
		ft_or(process, cw, vm);
	else if (state == XOR)
		ft_xor(process, cw, vm);
	else
		sort_state_16(state, process, cw, vm);
}

void	sort_state_16(int state, t_process *process, t_corewar *cw, t_vm *vm)
{
	if (state == ZJMP)
		ft_zjmp(process, cw, vm);
	else if (state == LDI)
		ft_ldi(process, cw, vm);
	else if (state == STI)
		ft_sti(process, cw, vm);
	else if (state == FORK)
		ft_fork(process, cw, vm);
	else if (state == LLD)
		ft_lld(process, cw, vm);
	else if (state == LLDI)
		ft_lldi(process, cw, vm);
	else if (state == LFORK)
		ft_lfork(process, cw, vm);
	else if (state == AFF)
		ft_aff(process, cw, vm);
	else
		skip_statement(process, cw, vm);
}