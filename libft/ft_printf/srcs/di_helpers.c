/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:20 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:24 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*handle_space_plus_min(char	*str, t_spec *fspec)
{
	if (fspec->plus == 1)
		str = ft_strjoin_free2("+", str);
	else
		str = ft_strjoin_free2(" ", str);
	return (str);
}

char	handle_space_plus(char c, t_spec *fspec)
{
	if (fspec->plus == 1)
		c = '+';
	else
		c = ' ';
	return (c);
}

char	*join_str(char *add_str, char *str_num, t_spec *fspec)
{
	if (fspec->min == 1)
		str_num = ft_strjoin_free1(str_num, add_str);
	else
		str_num = ft_strjoin_free2(add_str, str_num);
	free(add_str);
	return (str_num);
}

char	di_zero_spaces(char str, t_spec *fspec, long long int num)
{
	if (fspec->prec == -1 && fspec->zero == 1 && fspec->min != 1
		&& num < 0 && fspec->min_over != 1)
	{
		str = '-';
		fspec->min_over = 1;
	}
	else if (fspec->prec != -1 && fspec->prec <= fspec->width && num < 0
		&& fspec->min != 1 && fspec->zero == 1 && fspec->min_over != 1)
	{
		str = '-';
		fspec->min_over = 1;
	}
	else if (fspec->prec == -1 && fspec->zero == 1 && fspec->min != 1)
		str = '0';
	else
		str = ' ';
	return (str);
}
