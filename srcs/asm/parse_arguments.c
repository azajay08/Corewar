/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:45 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 17:33:45 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	verify_arguments(t_asm *assem, t_state *state)
{
	int	i;

	i = 0;
	while (i < state->arg_count)
	{
		if (arg_value(state->args[i]) == T_REG)
			check_reg_arg(assem, state->args[i]);
		else if (arg_value(state->args[i]) == T_DIR)
			check_dir_arg(assem, state->args[i]);
		else if (arg_value(state->args[i]) == T_IND)
			check_ind_arg(assem, state->args[i]);
		else
			error_exit1(ARG_ERR, assem);
		i++;
	}
	
}

void	get_arg_values(t_asm *assem, t_state *state)
{
	int	i;

	i = 0;
	verify_arguments(assem, state);
	while (i < state->arg_count)
	{
		
	}
}

void	parse_arguments(t_asm *assem)
{
	t_state	*state;

	state = assem->state;
	while (state)
	{
		get_arg_values(assem, state);
		state = state->next;
	}
}
