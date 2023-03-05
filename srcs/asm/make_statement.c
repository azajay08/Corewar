/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_statement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 04:04:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/05 23:05:21 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_statement(t_asm *assem)
{
	int i = 0;

	assem->line->num = 0;
	ft_printf("\nState Name: %s\n", g_op_tab[0].state_name);
	while (i < STATEMENT_MAX)
	{
		ft_printf("\nState Name: %s\n", g_op_tab[i].state_name);
		i++;
	}
}

void	append_statement(t_asm *assem, t_state *statement)
{
	t_state	*tmp;

	ft_printf("\nhere\n");
	tmp = assem->state;
	while (assem->state)
		assem->state = assem->state->next;
	assem->state->next = statement;
	assem->state = tmp;
}

char	*line_trim(t_asm *assem, int index)
{
	int		start;
	int		end;
	char	*line;
	char	*args;
	
	start = 0;
	if (is_label(assem, index))
		line = ft_strchr(assem->l_array[index]->line, LABEL_CHAR) + 1;
	else
		line = ft_strdup(assem->l_array[index]->line);
	end = ft_strlen(line);
	while (line[start] && ft_isspace(line[start]))
		start++;
	while (line[start] && !ft_isspace(line[start]))
		start++;
	args = ft_strsub(line, start, end - start);
	// free(line);
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

	line = line_trim(assem, index);
	statement = (t_state *)malloc(sizeof(t_state));
	if (!statement)
		error_exit1(STATE_FAIL, assem);
	if (line)
		get_statement(assem);
	statement->index = index;
	statement->byte_count = 0;
	label_check(assem, index);
	return (statement);
}