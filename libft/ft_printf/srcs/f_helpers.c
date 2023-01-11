/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_helpers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:33 by ajones            #+#    #+#             */
/*   Updated: 2022/10/06 02:22:05 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	sign_check(t_spec *fspec)
{
	if (fspec->plus == 1 || fspec->min_over == 1 || fspec->space == 1)
		return (1);
	else
		return (0);
}

char	*ft_ftoa_dec(long double num, t_spec *fspec)
{
	char		*str;
	long double	tmp;
	int			i;
	int			len;

	i = 1;
	len = fspec->prec + 1;
	tmp = num - (long long)num;
	str = ft_strnew(len);
	if (!str)
		return (NULL);
	str[0] = '.';
	while (i < len)
	{
		tmp *= 10;
		str[i] = (long long)tmp + '0';
		tmp -= (long long)tmp;
		i++;
	}
	return (str);
}

char	*ft_ftoa_int(long double num)
{
	char		*str;
	long double	tmp;
	int			i;
	int			len;

	i = 0;
	len = 0;
	tmp = num;
	while (tmp >= 10)
	{
		tmp /= 10;
		len++;
	}
	str = ft_strnew(len + 1);
	if (!str)
		return (NULL);
	while (len >= 0)
	{
		tmp = num / ft_power_double(10, len);
		str[i] = (long long)tmp + '0';
		num -= ((long long)tmp * ft_power_double(10.00, len));
		i++;
		len--;
	}
	return (str);
}

char	*ft_ftoa(long double num, t_spec *fspec)
{
	char			*dec_num;
	char			*str;

	str = ft_ftoa_int(num);
	if (fspec->prec > 0 || fspec->hash == 1)
	{
		if (fspec->prec == 0 && fspec->hash == 1)
			dec_num = ft_strdup(".");
		else
			dec_num = ft_ftoa_dec(num, fspec);
	}
	else
		dec_num = ft_strdup("");
	str = ft_strjoin_free1(str, dec_num);
	free (dec_num);
	return (str);
}

char	*make_n_str(t_spec *fspec, long double num)
{
	char		*str;
	long double	tmp;

	str = NULL;
	if (fspec->min_over == 1)
		num *= -1;
	tmp = num * ft_power_double(10, fspec->prec);
	if (tmp - (long long)tmp == 0.5)
	{
		if (((long long)tmp % 2 != 1 && fspec->mod != 5)
			|| ((long long)tmp % 2 != 1 && fspec->mod == 5 && fspec->prec == 0))
			num = tmp / ft_power_double(10, fspec->prec);
		else
			num = ft_round(num, fspec->prec);
	}
	else
		num = ft_round(num, fspec->prec);
	str = ft_ftoa(num, fspec);
	return (str);
}
