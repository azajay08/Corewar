/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 21:40:37 by ajones            #+#    #+#             */
/*   Updated: 2023/03/11 17:42:24 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	error_exit(char *exit_str)
{
	ft_printf("ERROR! %s", exit_str);
	exit(1);
}

void	error_exit1(char *exit_str, int error_code, t_asm *assem)
{
	if (error_code == LINE_REF)
		ft_printf("Error on Line [%i] %s", assem->lex_index + 1, exit_str);
	else
		ft_printf("ERROR! %s", exit_str);
	free_asm(assem);
	exit(1);
}
