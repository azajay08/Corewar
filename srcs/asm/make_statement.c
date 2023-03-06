/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 04:04:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/06 03:57:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_statement(t_asm *assem)
{
	int	i;

	i = 0;
	assem->line->num = 0;
	while (i < STATEMENT_MAX)
	{
		ft_printf("\nState Name: %s\n", g_op_tab[i].state_name);
		i++;
	}
}

void	append_statement(t_asm *assem, t_state *statement)
{
	t_state	*tmp;

	tmp = assem->state;
	while (assem->state->next)
		assem->state = assem->state->next;
	assem->state->next = statement;
	assem->state = tmp;
}

char	*line_trim(t_asm *assem, int index, char *line)
{
	int		start;
	int		end;
	char	*args;

	start = 0;
	if (is_label(assem, index))
		line = ft_strchr(line, LABEL_CHAR) + 1;
	end = ft_strlen(line);
	while (line[start] && ft_isspace(line[start]))
		start++;
	while (line[start] && !ft_isspace(line[start])
		&& ft_strchr(LABEL_CHARS, line[start]))
		start++;
	args = ft_strsub(line, start, end - start);
	if (!args)
		error_exit1(NO_ARGS, assem);
	if (line_has_comment(args))
		args = remove_comments(args);
	return (args);
}

t_state	*make_statement(t_asm *assem, int index)
{
	t_state	*statement;
	char	*line;
	char	**args;
	int		i;

	i = 0;
	line = line_trim(assem, index, assem->l_array[index]->line);
	args = ft_strsplit(line, SEPARATOR_CHAR);
	while (args[i])
		i++;
	if (i != g_op_tab[assem->state_code].arg_num)
		error_exit1(ARG_COUNT, assem);
	statement = (t_state *)malloc(sizeof(t_state));
	if (!statement)
		error_exit1(STATE_FAIL, assem);
	// if (line)
	// 	get_statement(assem);
	// statement->str = ft_strdup(line);
	ft_printf("\nline:\n%s", line);
	free(line);
	statement->index = index;
	statement->byte_count = 0;
	statement->next = NULL;
	label_check(assem, index);
	return (statement);
}
