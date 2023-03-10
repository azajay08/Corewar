/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:37 by ajones            #+#    #+#             */
/*   Updated: 2023/03/10 23:33:26 by ajones           ###   ########.fr       */
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
	if (assem->lex_index > 0)
		ft_printf("Line [%i] %s", assem->lex_index + 1, exit_str);
	else
		ft_putstr(exit_str);
	free_asm(assem);
	exit(1);
}
