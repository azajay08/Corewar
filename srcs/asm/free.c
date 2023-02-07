/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:59:41 by ajones            #+#    #+#             */
/*   Updated: 2023/02/07 14:13:56 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	free_asm(t_asm *assem)
{
	if (assem->champ_name)
		free(assem->champ_name);
	if (assem->filename)
		free(assem->filename);
	if (assem->comment)
		free(assem->comment);
}
