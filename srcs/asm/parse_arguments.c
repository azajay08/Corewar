/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:45 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 20:00:07 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	label_index(t_asm *assem, char *arg)
{
	t_label	*label;

	label = assem->label;
	while (label)
	{
		if (ft_strequ(label->label_name, arg))
			return (label->line_nb);
		label = label->next;
	}
	return (0);
}

int	label_value(t_asm *assem, t_state *state, int i)
{
	int	index;
	int	label_val;

	label_val = 0;
	index = label_index(assem, ft_strchr(state->args[i], LABEL_CHAR) + 1);
	if (index < state->index)
	{
		while (index < state->index)
		{
			label_val -= assem->l_array[index]->num;
			index++;
		}
	}
	else
	{
		while (index > state->index)
		{
			label_val += assem->l_array[index]->num;
			index--;
		}
	}
	return (label_val);
}

int	get_arg_value(t_asm *assem, t_state *state, int i)
{
	if (arg_value(state->args[i]) == T_REG)
		return(ft_atoi(ft_strchr(state->args[i], REG_CHAR) + 1));
	else if (arg_value(state->args[i]) == T_DIR)
	{
		if (state->args[i][1] == LABEL_CHAR)
			return (label_value(assem, state, i));
		else
			return(ft_atoi(ft_strchr(state->args[i], DIRECT_CHAR) + 1));
	}
	else if (arg_value(state->args[i]) == T_IND)
	{
		if (state->args[i][0] == LABEL_CHAR)
			return (label_value(assem, state, i));
		else
			return(ft_atoi(state->args[i]));
	}
	else
		error_exit1(ARG_ERR, assem);
	return (0);
}

void	parse_arg_values(t_asm *assem, t_state *state)
{
	int	i;

	i = 0;
	verify_arguments(assem, state);
	while (i < state->arg_count)
	{
		state->arg_val[i] = get_arg_value(assem, state, i);
		i++;
	}
}

void	parse_arguments(t_asm *assem)
{
	t_state	*state;

	state = assem->state;
	while (state)
	{
		parse_arg_values(assem, state);
		state = state->next;
	}
}
