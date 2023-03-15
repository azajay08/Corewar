/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:23:45 by ajones            #+#    #+#             */
/*   Updated: 2023/03/15 02:49:18 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
	label_index returns the index of a matching label name
*/

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

/*
	label_value calculates the distance from the current position to the
	targeted label. The calculations differ slightly when moving forwards, to
	moving to a label backwards.
*/

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
			label_val += assem->l_array[index - 1]->num;
			index--;
		}
	}
	return (label_val);
}

/*
	Now that the arguments have been verified, we move onto actually assigning
	the number value to each argument depending on what kind of argument it
	is. The value can just be whatever numbers are given as arguments in the
	correct format. If it is a label however, the value needs to be calculated
	by distance of bytes to that particular label, using label_value.

	atoi_limit_neg/pos go to arg_utils4.c. The purpose of this function is to
	check whether the number given as an argument goes out of the limits of a 
	long long int. If this is the case, the value will either be set to 0 or -1
	depending if the number agruemnt given has surpassed the the LONG_MIN or
	LONG_MAX. If it is within the limits, a normal ft_atoi returns an integar
	value.
*/

int	get_arg_value(t_asm *assem, t_state *state, int i)
{
	if (arg_value(state->args[i]) == T_REG)
		return (ft_atoi(ft_strchr(state->args[i], REG_CHAR) + 1));
	else if (arg_value(state->args[i]) == T_DIR)
	{
		if (state->args[i][1] == LABEL_CHAR)
			return (label_value(assem, state, i));
		if (state->args[i][1] == '-')
			return (atoi_limit_neg(ft_strchr(state->args[i], DIRECT_CHAR) + 1));
		else
			return (atoi_limit_pos(ft_strchr(state->args[i], DIRECT_CHAR) + 1));
	}
	else if (arg_value(state->args[i]) == T_IND)
	{
		if (state->args[i][0] == LABEL_CHAR)
			return (label_value(assem, state, i));
		if (state->args[i][0] == '-')
			return (atoi_limit_neg(state->args[i]));
		else
			return (atoi_limit_pos(state->args[i]));
	}
	else
		error_exit1(ARG_ERR, LINE_REF, assem);
	return (0);
}

/*
	Parse_arg_values goes through the arguments of the statement and gets
	each value, only after being verified with verify_arguments in verify.c
*/

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

/*
	Parse_arguments goes through the t_state list, verifies the arguments
	for that particular statement and then gets the values for them.
*/

void	parse_arguments(t_asm *assem)
{
	t_state	*state;

	state = assem->state;
	while (state)
	{
		assem->lex_index = state->index;
		parse_arg_values(assem, state);
		state = state->next;
	}
}
