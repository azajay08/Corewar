/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:37 by ajones            #+#    #+#             */
/*   Updated: 2023/02/07 14:15:43 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(char *exit_str)
{
	ft_putstr(exit_str);
	exit(1);
}

void	error_exit1(t_asm *assem, char *exit_str)
{
	free_asm(assem);
	free(assem);
	ft_putstr(exit_str);
	exit(1);
}