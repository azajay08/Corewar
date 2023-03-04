/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:19:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/04 21:22:12 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_statement(char *state, t_asm *assem)
{
	int	i;

	i = 0;
	while (i < STATEMENT_MAX)
	{
		if (ft_strequ(state, g_op_tab[i].state_name))
		{
			free(state);
			return (1);
		}
		i++;
	}
	free(state);
	error_exit1(INV_STATE, assem);
	return (0);
}

int	line_has_statement(t_asm *assem, int index, char *line)
{
	int		i;
	int		end;
	char	*state;

	i = 0;
	end = 0;
	state = NULL;
	if (is_label(assem, index))
		line = ft_strchr(line, LABEL_CHAR) + 1;
	if (line_check(line))
		return (0);
	while (ft_isspace(line[i]))
		i++;
	if (!line[i])
		return (0);
	end = i;
	while (line[end] && ft_strchr(LABEL_CHARS, line[end]))
		end++;
	if (!line[end])
		error_exit1(INV_STATE, assem);
	state = ft_strsub(line, i, end - i);
	if (is_statement(state, assem))
		return (1);
	return (0);
}

void	label_check(t_asm *assem, int index)
{
	t_label	*label;

	label = assem->label;
	while (assem->label)
	{
		if (assem->label->state == true)
		{
			assem->label->state == false
			assem->label->line_nb = index;
		}
		assem->label = assem->label->next;
	}
	assem->label = label;
}
