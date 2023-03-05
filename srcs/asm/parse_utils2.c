/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 21:19:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/05 04:07:02 by ajones           ###   ########.fr       */
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
