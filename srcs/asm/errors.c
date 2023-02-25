/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:37 by ajones            #+#    #+#             */
/*   Updated: 2023/02/13 17:00:26 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(char *exit_str)
{
	ft_putstr(exit_str);
	exit(1);
}

void	error_exit1(char *exit_str, t_asm *assem)
{
	free_asm(assem);
	free(assem);
	ft_putstr(exit_str);
	system("leaks asm");
	exit(1);
}
