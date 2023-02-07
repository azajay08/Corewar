/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 19:21:12 by ajones            #+#    #+#             */
/*   Updated: 2023/02/07 03:09:11 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	init_asm(t_asm *assem, char *file_input)
{
	int	len;

	len = ft_strlen(file_input) - 2;
	assem->filename = ft_strsub(file_input, 0, len);
	assem->cor_name = ft_strjoin(assem->filename, ".cor");
}
