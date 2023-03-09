/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:41 by ajones            #+#    #+#             */
/*   Updated: 2023/03/09 17:30:02 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_label(t_asm *assem)
{
	t_label	*temp;

	while (assem->label)
	{
		temp = assem->label;
		assem->label = assem->label->next;
		ft_strdel(&temp->label_name);
		free(temp);
	}
}

void	free_line_array(t_asm *assem)
{
	int	i;

	i = 0;
	while (i < assem->line_count)
	{
		ft_strdel(&assem->l_array[i]->line);
		free(assem->l_array[i]);
		i++;
	}
	free(assem->l_array);
}

void	free_line(t_asm *assem)
{
	t_line	*temp;

	while (assem->line)
	{
		temp = assem->line;
		assem->line = assem->line->next;
		ft_strdel(&temp->line);
		free(temp);
	}
}

void	free_statement(t_asm *assem)
{
	t_state	*temp;

	while (assem->state)
	{
		temp = assem->state;
		if (temp->args)
			ft_2d_free(temp->args);
		assem->state = assem->state->next;
		free(temp);
	}
}

/*
	Goes through the asm struct and frees anything that has been allocated.
*/

void	free_asm(t_asm *assem)
{
	if (assem->filename)
		free(assem->filename);
	if (assem->champ_name)
		free(assem->champ_name);
	if (assem->champ_com)
		free(assem->champ_com);
	if (assem->line)
		free_line(assem);
	if (assem->l_array)
		free_line_array(assem);
	if (assem->label)
		free_label(assem);
	if (assem->state)
		free_statement(assem);
	free(assem);
}
