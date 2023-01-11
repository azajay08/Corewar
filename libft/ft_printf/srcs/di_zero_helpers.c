/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_zero_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:27 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:30 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_di_zero_prec(char *str_num, t_spec *fspec)
{
	char	*num;

	free(str_num);
	if (fspec->plus == 1)
		num = ft_strdup("+");
	else if (fspec->space == 1)
		num = ft_strdup(" ");
	else
		num = ft_strdup("");
	return (num);
}

char	*manage_di_zero(char *str_num, t_spec *fspec)
{
	if (fspec->prec == 0)
	{
		str_num = manage_di_zero_prec(str_num, fspec);
		return (str_num);
	}
	if (fspec->plus == 1 && fspec->width <= 1 && fspec->prec == -1)
	{
		str_num = ft_strjoin_free2("+", str_num);
		fspec->zero_over = 1;
	}
	else if (fspec->space == 1 && fspec->width <= 1 && fspec->prec == -1)
	{
		str_num = ft_strjoin_free2(" ", str_num);
		fspec->zero_over = 1;
	}
	return (str_num);
}
