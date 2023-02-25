/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:16 by ajones            #+#    #+#             */
/*   Updated: 2023/02/14 19:51:32 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	verify_name_com(t_asm *assem, t_line *line)
{
	if (!assem->champ_name || !assem->champ_com || !line)
		error_exit1(INV_FILE, assem);
	if (ft_strlen(assem->champ_name) > PROG_NAME_LENGTH)
		error_exit1(LONG_NAME, assem);
	if (ft_strlen(assem->champ_com) > COMMENT_LENGTH)
		error_exit1(LONG_COM, assem);
}
