/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:51:25 by ajones            #+#    #+#             */
/*   Updated: 2023/03/04 22:05:51 by ajones           ###   ########.fr       */
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

int	is_label(t_asm *assem, int index)
{
	t_label	*label;

	label = assem->label;
	ft_printf("\nindex: %i\n", index);
	while (label)
	{
		ft_printf("\nlabel index: %i\n", label->line_nb);
		if (label->line_nb == index)
		{
			label->state = true;
			return (1);
		}
		label = label->next;
	}
	return (0);
}

int	duplicate_label(t_asm *assem, char *str)
{
	t_label	*label;

	label = assem->label;
	while (label)
	{
		if (ft_strequ(str, label->label_name))
		{
			free(str);
			return (1);
		}
		label = label->next;
	}
	return (0);
}

int	statement_label(char *line, int start)
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
