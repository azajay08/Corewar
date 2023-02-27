/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:59:03 by ajones            #+#    #+#             */
/*   Updated: 2023/02/27 21:41:48 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_label(char *line, int i)
{
	int		start;
	char	*label;

	start = i;
	while (line[i] && line[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (NULL);
		i++;
	}
	if (line[i] != LABEL_CHAR)
		label = NULL;
	else
		label = ft_strsub(line, start, i - start);
	return (label);
}

void	append_label(t_asm *assem, t_label *label)
{
	t_label	*temp;

	temp = assem->label;
	while (assem->label->next)
		assem->label = assem->label->next;
	assem->label->next = label;
	assem->label = temp;
}

t_label	*make_label(t_asm *assem, t_line *line, int i)
{
	t_label	*label;

	label = (t_label *)malloc(sizeof(t_label));
	if (!label)
		error_exit1(LBL_FAIL, assem);
	label->label_name = get_label(line->line, i);
	if (!label->label_name)
		error_exit1(LBL_NAME, assem);
	label->line_nb = line->num;
	label->next = NULL;
	return (label);
}

int	is_statement(char *line, int start)
{
	int		i;
	char	*str;

	i = start;
	str = NULL;
	while (line[i] && !ft_isspace(line[i]))
		i++;
	if (i == start)
		return (1);
	str = ft_strsub(line, start, i - start);
	i = 0;
	while (i < STATEMENT_MAX)
	{
		if (ft_strequ(str, g_op_tab[i].state_name))
		{
			free(str);
			return (1);
		}
		i++;
	}
	free(str);
	return (0);
}

void	parse_labels(t_asm *assem, t_line *head)
{
	int		i;
	t_line	*line;
	t_label	*label;

	line = head;
	if (!line)
		error_exit1(LINE_FAIL, assem);
	while (line)
	{
		i = 0;
		while (line->line[i] && ft_isspace(line->line[i]))
			i++;
		if (line->line[i] && ft_strchr(LABEL_CHARS, line->line[i])
			&& !is_statement(line->line, i))
		{
			label = make_label(assem, line, i);
			if (!assem->label)
				assem->label = label;
			else
				append_label(assem, label);
		}
		line = line->next;
	}
}
