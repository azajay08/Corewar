/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:50 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:52 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_f_flags(char *str, t_spec *fspec)
{
	if (fspec->min_over == 1)
		str = ft_strjoin_free2("-", str);
	else if (fspec->plus == 1)
		str = ft_strjoin_free2("+", str);
	else if (fspec->space == 1)
		str = ft_strjoin_free2(" ", str);
	return (str);
}

char	*manage_f_width(char *str, int i, t_spec *fspec)
{
	char	*add_str;
	int		z;

	z = 0;
	add_str = ft_strnew(i);
	if (!add_str)
		return (NULL);
	add_str[i] = '\0';
	if (fspec->zero == 1 && fspec->min == 0 && sign_check(fspec) == 1)
		i--;
	while (i--)
	{
		if (fspec->zero == 1 && fspec->min == 0)
			add_str[z++] = '0';
		else
			add_str[z++] = ' ';
	}
	if (fspec->min == 1)
		str = ft_strjoin_free1(str, add_str);
	else
		str = ft_strjoin_free2(add_str, str);
	free(add_str);
	if (fspec->zero == 1 && fspec->zero_over == 0)
		str = manage_f_flags(str, fspec);
	return (str);
}

char	*manage_f(char *str, t_spec *fspec)
{
	int	len;
	int	i;

	len = ft_strlen(str);
	if (fspec->zero == 0 || fspec->width <= len || fspec->min == 1)
	{
		if (fspec->min_over == 1 || fspec->plus == 1 || fspec->space == 1)
		{
			if (fspec->min_over == 1)
				str = ft_strjoin_free2("-", str);
			else if (fspec->plus == 1)
				str = ft_strjoin_free2("+", str);
			else if (fspec->space == 1)
				str = ft_strjoin_free2(" ", str);
			fspec->zero_over = 1;
			len++;
		}
	}
	i = fspec->width - len;
	if (i > 0)
		str = manage_f_width(str, i, fspec);
	return (str);
}

char	*nan_inf_dup(char *str, long double num, t_spec *fspec)
{
	if (num != num)
	{
		str = ft_strdup("nan");
		fspec->plus = 0;
		fspec->space = 0;
	}
	else if (num == 1.0 / 0.0)
		str = ft_strdup("inf");
	else if (num == -1.0 / 0.0)
	{
		str = ft_strdup("inf");
		fspec->min_over = 1;
	}
	fspec->zero = 0;
	fspec->prec = -1;
	return (str);
}

int	form_f(va_list *ap, t_spec *fspec)
{
	char		*str_num;
	long double	arg_num;
	int			len;

	str_num = NULL;
	arg_num = manage_f_mods(ap, fspec);
	if (fspec->prec == -1)
		fspec->prec = 6;
	if (ft_is_neg(arg_num))
		fspec->min_over = 1;
	if (arg_num != arg_num || arg_num == -1.0 / 0.0 || arg_num == 1.0 / 0.0)
		str_num = nan_inf_dup(str_num, arg_num, fspec);
	else
		str_num = make_n_str(fspec, arg_num);
	str_num = manage_f(str_num, fspec);
	ft_putstr(str_num);
	len = ft_strlen(str_num);
	free (str_num);
	return (len);
}
