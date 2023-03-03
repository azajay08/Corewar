/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:59:03 by ajones            #+#    #+#             */
/*   Updated: 2023/03/03 20:19:05 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	append_label(t_asm *assem, t_label *label)
{
	t_label	*temp;

	temp = assem->label;
	while (assem->label->next)
		assem->label = assem->label->next;
	assem->label->next = label;
	assem->label = temp;
}

char	*get_label(t_asm *assem, char *line, int i)
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
	if (duplicate_label(assem, label))
		return (NULL);
	return (label);
}

t_label	*make_label(t_asm *assem, int index, int i)
{
	t_label	*label;
	char	*str;

	str = get_label(assem, assem->l_array[index]->line, i);
	if (!str)
		return (NULL);
	label = (t_label *)malloc(sizeof(t_label));
	if (!label)
		error_exit1(LBL_FAIL, assem);
	label->label_name = ft_strdup(str);
	if (!label->label_name)
		error_exit1(LBL_NAME, assem);
	label->line_nb = index;
	label->next = NULL;
	label->state = false;
	free(str);
	return (label);
}

void	sort_label(t_asm *assem, t_label *label)
{
	if (!assem->label)
		assem->label = label;
	else
		append_label(assem, label);
}

void	parse_labels(t_asm *assem, int index)
{
	int		i;
	t_label	*label;
	t_line	**line;

	line = assem->l_array;
	if (index >= assem->line_count)
		error_exit1(INV_FILE, assem);
	while (index < assem->line_count)
	{
		i = 0;
		while (line[index]->line[i] && ft_isspace(line[index]->line[i]))
			i++;
		if (line[index]->line[i] && ft_strchr(LABEL_CHARS, line[index]->line[i])
			&& !statement_label(line[index]->line, i))
		{
			label = make_label(assem, index, i);
			if (!label)
			{
				index++;
				continue ;
			}
			sort_label(assem, label);
		}
		index++;
	}
}
