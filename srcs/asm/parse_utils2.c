/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:19:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/06 02:55:08 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

int	line_has_comment(char *line)
{
	int i;

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

	i = ft_strlen(line);
	str = NULL;
	while (i)
	{
		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
		{
			str = ft_strsub(line, 0, i - 1);
			free(line);
			return (str);
		}
		i--;
	}
	return (line);
}