/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:49 by ajones            #+#    #+#             */
/*   Updated: 2023/02/07 15:46:13 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	read_file(t_asm *assem, char *file)
{
	int fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit1(ERR_FILE, assem);
}
