/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 04:04:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/24 13:03:03 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
	label_check will iterate through the label list and if a boolean is on 
	for any of the labels, the index of the current statement is given to the 
	label/labels. This is so the position of the label can be found easily
	if a label is given as an argument.
*/
void	label_check(t_asm *assem, int index)
{
	t_label	*label;

	label = assem->label;
	while (assem->label)
	{
		if (assem->label->state == true)
		{
			assem->label->state = false;
			assem->label->line_nb = index;
		}
		assem->label = assem->label->next;
	}
	assem->label = label;
}

/*
	get_arguments returns a 2d array of arguments. Each argument will be
	trimmed down to make it easier to extract the data from it.
*/
char	**get_arguments(t_asm *assem, char **args)
{
	int		i;
	char	**state_arg;

	i = 0;
	while (args[i])
		i++;
	state_arg = (char **)malloc(sizeof(char *) * (i + 1));
	if (!state_arg)
		error_exit1(ARG_STR, NO_REF, assem);
	i = 0;
	while (args[i])
	{
		state_arg[i] = ft_strtrim(args[i]);
		if (!state_arg[i])
			error_exit1(ARG_STR, NO_REF, assem);
		i++;
	}
	state_arg[i] = NULL;
	ft_2d_free(args);
	return (state_arg);
}

/*
	Init_statement assigns the data to the t_state element. From here, it gets
	the arguments from the statement in the form of a 2d char array so the
	argument can be looked at more closely as an individual string.

	get_byte_count goes to arg_utils1.c. This returns the number of bytes that
	this particular statement has. This can then be used to calculate distances
	to labels if given as an argument.

	get_arg_result goes to arg_utils2.c which returns result of the argument
	types.
*/
void	init_statement(t_asm *assem, t_state *statement, int i, char **args)
{
	statement->args = get_arguments(assem, args);
	statement->arg_count = i;
	statement->state_code = assem->state_code;
	statement->byte_count = get_byte_count(assem, statement->args);
	statement->result = get_arg_result(assem, statement->args);
	statement->next = NULL;
}

/*
	line_trim returns the line back but without all the uneccesary things such
	as comments or trailing commas. This is also another verification check.
*/
char	*line_trim(t_asm *assem, int index, char *line)
{
	int		start;
	int		end;
	char	*args;

	start = 0;
	if (is_label(assem, index) || skip_duplicate_label(assem, line))
		line = ft_strchr(line, LABEL_CHAR) + 1;
	end = ft_strlen(line);
	while (line[start] && ft_isspace(line[start]))
		start++;
	while (line[start] && !ft_isspace(line[start])
		&& ft_strchr(LABEL_CHARS, line[start]))
		start++;
	if (!ft_isspace(line[start]) && line[start] != DIRECT_CHAR)
		error_exit1(ARG_ERR, LINE_REF, assem);
	args = ft_strsub(line, start, end - start);
	if (!args)
		error_exit1(NO_ARGS, LINE_REF, assem);
	if (line_has_comment(args))
		args = remove_comments(args);
	if (comma_at_end(args))
		error_exit1(COMMA, LINE_REF, assem);
	return (args);
}

/*
	Make_statement returns data about a statement to the t_state struct.

	The byte count is added to the line array as the value of the line.
*/
t_state	*make_statement(t_asm *assem, int index)
{
	t_state	*statement;
	char	*line;
	char	**args;
	int		i;

	i = 0;
	assem->lex_index = index;
	line = line_trim(assem, index, assem->l_array[index]->line);
	args = ft_strsplit(line, SEPARATOR_CHAR);
	free(line);
	while (args[i])
		i++;
	if (i != g_op_tab[assem->state_code].arg_num)
		error_exit1(ARG_COUNT, LINE_REF, assem);
	statement = (t_state *)malloc(sizeof(t_state));
	if (!statement)
		error_exit1(STATE_FAIL, NO_REF, assem);
	init_statement(assem, statement, i, args);
	statement->index = index;
	assem->l_array[index]->num = statement->byte_count;
	label_check(assem, index);
	return (statement);
}
