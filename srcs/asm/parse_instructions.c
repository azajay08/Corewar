/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:56:46 by ajones            #+#    #+#             */
/*   Updated: 2023/03/24 13:03:33 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
	Adds the stateement element to the end of the t_state list
*/
void	append_statement(t_asm *assem, t_state *statement)
{
	t_state	*tmp;

	tmp = assem->state;
	while (assem->state->next)
		assem->state = assem->state->next;
	assem->state->next = statement;
	assem->state = tmp;
}

int	is_statement(t_asm *assem, char *state)
{
	int	i;

	i = 0;
	while (i < STATEMENT_MAX)
	{
		if (ft_strequ(state, g_op_tab[i].state_name))
		{
			assem->state_code = i;
			free(state);
			return (1);
		}
		i++;
	}
	free(state);
	return (0);
}

/*
	line_has_statement contains is_label which is in parse_utils1.c. This will
	recognise if a label is on that line. If it find a label, a boolean is
	triggered to be on alert to be assigned to a statement. Multiple labels
	can refer the the same statement line. skip_duplicate_labels in
	parse_utils2.c checks whether the label is a duplicate so it can be
	ignored for argument reference.
*/
int	line_has_statement(t_asm *assem, int index, char *line)
{
	int		i;
	int		end;
	char	*state;

	i = 0;
	end = 0;
	state = NULL;
	if (is_label(assem, index) || skip_duplicate_label(assem, line))
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
		error_exit1(SYNT_ERR, LINE_REF, assem);
	state = ft_strsub(line, i, end - i);
	if (is_statement(assem, state))
		return (1);
	error_exit1(SYNT_ERR, LINE_REF, assem);
	return (0);
}

/*
	Parse_instructions goes through all the lines and checks which lines have
	statements and then saves them to the t_state struct. The head, like all 
	the other structs will be saved to the t_asm struct.

	Line_has_statement acts as a verification for statements It also gathers
	information about which statements they are and the lines they are on, so
	they can be referred to by index.

	Once a valid statement has been found, we then go to make_statement.c
	where the line will be disected more.

	Once all statements have been parsed and verified, we then go to
	parse_arguments.
*/
void	parse_instructions(t_asm *assem, int index)
{
	t_state	*statement;

	while (index < assem->line_count)
	{
		assem->lex_index = index;
		if (assem->l_array[index]->line[0]
			&& line_has_statement(assem, index, assem->l_array[index]->line))
		{
			statement = make_statement(assem, index);
			if (!assem->state)
				assem->state = statement;
			else
				append_statement(assem, statement);
		}
		index++;
	}
	if (!assem->state && !assem->label)
		error_exit1(NO_EXE, NO_REF, assem);
	parse_arguments(assem);
}
