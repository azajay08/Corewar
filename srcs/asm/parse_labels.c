/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_labels.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:59:03 by ajones            #+#    #+#             */
/*   Updated: 2023/02/17 16:28:44 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	parse_labels(t_asm *assem, t_line *head)
{
	t_line	*line;

	line = head;
	if (!line)
		error_exit1(LINE_FAIL, assem);
}
