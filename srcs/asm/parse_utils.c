/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:51:25 by ajones            #+#    #+#             */
/*   Updated: 2023/02/14 20:07:33 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	line_check(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == COMMENT_CHAR)
			return (1);
		else if (line[i] == ALT_COMMENT_CHAR)
			return (1);
		else if (line[i] == '\0')
			return (1);
		else if (ft_isspace(line[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	cmd_str_check(t_asm *assem, char *line, char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (ft_isspace(line[i]) && line[i])
		i++;
	while (line[i] == cmd[j])
	{
		i++;
		j++;
	}
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (line[i] != '"' || (int)ft_strlen(cmd) != j)
		error_exit1(INV_FILE, assem);
	return (i);
}
