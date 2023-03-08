/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:19:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/08 21:55:54 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

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

// char	*remove_comments(char *line)
// {
// 	int		i;
// 	char	*str;

// 	i = ft_strlen(line);
// 	str = NULL;
// 	while (i)
// 	{
// 		if (line[i] == COMMENT_CHAR || line[i] == ALT_COMMENT_CHAR)
// 		{
// 			str = ft_strsub(line, 0, i);
// 			free(line);
// 			return (str);
// 		}
// 		i--;
// 	}
// 	return (line);
// }

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
