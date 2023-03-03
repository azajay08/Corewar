/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:56:46 by ajones            #+#    #+#             */
/*   Updated: 2023/03/03 03:22:07 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	is_label(t_asm *assem, int index)
{
	t_label	*label;

	label = assem->label;
	while (label)
	{
		if (label->line_nb == index)
			return (1);
		label = label->next;
	}
	return (0);
}

int	line_has_statment(t_asm *assem, int index)
{
	int	i;

	i = 0;
	if (is_label(assem, i));
	{
		while (assem->l_array[index]->line[i] != LABEL_CHAR)
			i++;
	}
	return (0);
}

void	parse_instructions(t_asm *assem, int i)
{
	t_line	**line;

	line = assem->l_array;
	while (i < assem->line_count)
	{
		if (line[i]->line[0] && line_has_statement(assem, i))
		{
			get_statement(assem, i);
		}
		i++;
	}
	if (!assem->state)
		error_exit1(INSTRUCT, assem);
}