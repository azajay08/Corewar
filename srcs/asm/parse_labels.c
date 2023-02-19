/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:59:03 by ajones            #+#    #+#             */
/*   Updated: 2023/02/19 23:09:26 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_label(char *line)
{
	int		i;
	char	*label;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
	{
		if (!ft_strchr(LABEL_CHARS, line[i]))
			return (NULL);
		i++;
	}
	label = ft_strsub(line, 0, i);
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

t_label	*make_label(t_asm *assem, t_line *line)
{
	t_label	*label;

	label = (t_label*)malloc(sizeof(t_label));
	if (!label)
		error_exit1(LBL_FAIL, assem);
	label->label_name = get_label(line->line);
	if (!label->label_name)
		error_exit1(LBL_NAME, assem);
	label->line_nb = line->num;
	label->next = NULL;
	return (label);
}

void	parse_labels(t_asm *assem, t_line *head)
{
	t_line	*line;
	t_label	*label;

	line = head;
	if (!line)
		error_exit1(LINE_FAIL, assem);
	while (line)
	{
		if (line->line[0] && ft_strchr(LABEL_CHARS ,line->line[0]))
		{
			label = make_label(assem, line);
			if (!assem->label)
				assem->label = label;
			else
				append_label(assem, label);
		}
		line = line->next;
	}
}
