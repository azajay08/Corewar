/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:41 by ajones            #+#    #+#             */
/*   Updated: 2023/02/11 22:51:59 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

// static void	print_map(t_asm *assem)
// {
// 	t_line	*tmp;

// 	tmp = assem->line;
// 	while (tmp)
// 	{
// 		ft_putstr(tmp->line);
// 		ft_putchar('\n');
// 		tmp = tmp->next;
// 	}
// }

void	free_line(t_asm *assem)
{
	t_line	*temp;

	while (assem->line)
	{
		temp = assem->line;
		ft_printf("\nline: %s", temp->line);
		assem->line = assem->line->next;
		ft_strdel(&temp->line);
		free(temp);
	}
}

void	free_asm(t_asm *assem)
{
	// print_map(assem);
	// print_map(assem);
	if(assem->line)
		free_line(assem);
	if (assem->champ_name)
		free(assem->champ_name);
	if (assem->filename)
		free(assem->filename);
	if (assem->champ_com)
		free(assem->champ_com);
}
