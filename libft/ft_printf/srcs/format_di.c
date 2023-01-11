/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_di.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:44 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:46 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_neg_di(char *str, int i, t_spec *fspec)
{
	if (fspec->zero == 0)
	{
		str = ft_strjoin_free2("-", str);
		fspec->min_over = 1;
	}
	else if (fspec->zero == 1 && fspec->min == 1)
	{
		str = ft_strjoin_free2("-", str);
		fspec->min_over = 1;
	}
	else if (fspec->zero == 1 && fspec->width <= i)
	{
		str = ft_strjoin_free2("-", str);
		fspec->min_over = 1;
	}	
	else if (fspec->zero == 1 && fspec->prec != -1
		&& fspec->prec <= fspec->width)
	{
		str = ft_strjoin_free2("-", str);
		fspec->min_over = 1;
	}	
	return (str);
}

char	*manage_di_width(long long int num, char *str_num, t_spec *fspec, int i)
{
	char	*add_str;
	int		s;

	s = 0;
	add_str = ft_strnew(i);
	if (fspec->space == 1 || fspec->plus == 1)
	{
		if (fspec->prec == -1 && num >= 0)
		{
			if (fspec->min == 1 || fspec->zero == 0)
				str_num = handle_space_plus_min(str_num, fspec);
			else
				add_str[s++] = handle_space_plus(*add_str, fspec);
			i--;
		}
		else if (fspec->prec < numlen_sign(num) && num > 0)
		{
			str_num = handle_space_plus_min(str_num, fspec);
			i--;
		}
	}
	while (i--)
		add_str[s++] = di_zero_spaces(*add_str, fspec, num);
	str_num = join_str(add_str, str_num, fspec);
	return (str_num);
}

char	*manage_di_prec(long long int arg_num, char *str_num, t_spec *fspec)
{
	char	*add_str;
	int		i;
	int		z;

	z = 0;
	i = fspec->prec - ft_strlen(str_num);
	if (arg_num < 0 || fspec->plus == 1 || fspec->space == 1)
		i++;
	add_str = ft_strnew(i);
	if (arg_num < 0)
	{
		add_str[z++] = '-';
		fspec->min_over = 1;
	}
	else if (fspec->plus == 1 && arg_num >= 0)
		add_str[z++] = '+';
	else if (fspec->space == 1 && arg_num >= 0)
		add_str[z++] = ' ';
	if (z == 1)
		i--;
	while (i--)
		add_str[z++] = '0';
	str_num = ft_strjoin_free2(add_str, str_num);
	free(add_str);
	return (str_num);
}

char	*manage_di(long long int arg_num, char *str_num, t_spec *fspec)
{
	int	i;

	i = ft_strlen(str_num);
	if (fspec->prec >= i)
		str_num = manage_di_prec(arg_num, str_num, fspec);
	else if (arg_num < 0)
		str_num = manage_neg_di(str_num, i, fspec);
	else if (fspec->plus == 1 && fspec->width <= i && arg_num > 0)
		str_num = ft_strjoin_free2("+", str_num);
	else if (fspec->space == 1 && arg_num > 0 && fspec->width <= i)
		str_num = ft_strjoin_free2(" ", str_num);
	if (arg_num == 0)
		str_num = manage_di_zero(str_num, fspec);
	i = ft_strlen(str_num);
	if (fspec->width >= i && fspec->zero_over != 1)
	{
		i = fspec->width - ft_strlen(str_num);
		str_num = manage_di_width(arg_num, str_num, fspec, i);
	}
	return (str_num);
}

int	form_di(va_list *ap, t_spec *fspec)
{
	long long int	arg_num;
	char			*str_num;
	int				len;

	len = 0;
	arg_num = manage_di_mods(ap, fspec);
	str_num = ft_itoa_signed(arg_num);
	str_num = manage_di(arg_num, str_num, fspec);
	ft_putstr(str_num);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}
