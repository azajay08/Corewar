/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:19:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/10 22:56:40 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	end_line_space(t_asm *assem)
{
	int		i;
	t_line	*line;

	i = 0;
	line = assem->line;
	while (line->next)
		line = line->next;
	while (line->line[i])
	{
		if (line->line[i] == COMMENT_CHAR || line->line[i] == ALT_COMMENT_CHAR)
			return (1);
		if (!ft_isspace(line->line[i]))
			return (0);
		i++;
	}
	return (1);
}

int	line_has_comment(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
			return (1);
		i++;
	}
	return (0);
}

char	*remove_comments(char *line)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		{
			str = ft_strsub(line, 0, i);
			free(line);
			return (str);
		}
		i++;
	}
	return (line);
}

int	comma_at_end(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	while (i && ft_isspace(line[i]))
		i--;
	if (line[i] == SEPARATOR_CHAR)
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int	skip_duplicate_label(t_asm *assem, char *line)
{
	int		i;
	char	*label;

	i = 0;
	while (line[i] && line[i] != LABEL_CHAR)
		i++;
	label = ft_strsub(line, 0, i);
	if (duplicate_label(assem, label))
	{
		return (1);
	}
	else
	{
		free(label);
		return (0);
	}
}
