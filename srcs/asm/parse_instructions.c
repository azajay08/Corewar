/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:56:46 by ajones            #+#    #+#             */
/*   Updated: 2023/03/03 21:45:19 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_statement(char *state, t_asm *assem)
{
	int	i;

	i = 0;
	while (i < STATEMENT_MAX)
	{
		if (ft_strequ(state, g_op_tab[i].state_name))
		{
			free(state);
			return (1);
		}
		i++;
	}
	free(state);
	error_exit1(INV_STATE, assem);
	return (0);
}

int	is_label(t_asm *assem, int index)
{
	t_label	*label;

	label = assem->label;
	while (label)
	{
		if (label->line_nb == index)
		{
			label->state = true;
			return (1);
		}
		label = label->next;
	}
	return (0);
}

int	line_has_statement(t_asm *assem, int index, char *line)
{
	int		i;
	int		end;
	char	*state;

	i = 0;
	end = 0;
	state = NULL;
	if (is_label(assem, index))
		line = ft_strchr(line, LABEL_CHAR) + 1;
	if (line_check(line))
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	end = i;
	while (line[end] && ft_strchr(LABEL_CHARS, line[end]))
		end++;
	if (!line[end])
		error_exit1(INV_STATE, assem);
	state = ft_strsub(line, i, end - i);
	if (is_statement(state, assem))
		return (1);
	return (0);
}

void	get_statement(t_asm *assem, int index)
{
	t_state	*statement;
	
	statement = NULL;
}

void	parse_instructions(t_asm *assem, int index)
{
	t_state	*statement;
	
	while (index < assem->line_count)
	{
		if (assem->l_array[index]->line[0]
			&& line_has_statement(assem, index, assem->l_array[index]->line))
		{
			statement = make_statement(assem, index);
			if (!assem->state)
				assem->state = statement;
			else
				append_statement(assem, index, statement);
			ft_printf("\nThere is a statment!\n");
			get_statement(assem, index);
		}
		index++;
	}
	if (!assem->state)
		error_exit1(INSTRUCT, assem);
}
