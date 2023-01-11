/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:25 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:54:28 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	hash_check(t_spec *fspec, int len, unsigned long long int num)
{
	if (fspec->width > len + 2 && fspec->prec == -1 && fspec->zero == 1
		&& fspec->min == 0 && num > 0 && fspec->hash != 0)
		return (1);
	else
		return (0);
}

char	*hash_w_z(char *str, t_spec *fspec, int len, unsigned long long int n)
{
	if (hash_check(fspec, len, n))
	{
		if (fspec->c == 'X')
		{
			str[0] = '0';
			str[1] = 'X';
		}	
		else
		{
			str[0] = '0';
			str[1] = 'x';
		}
		fspec->hash = 0;
	}
	return (str);
}

char	*manage_hash_x(char *str_num, t_spec *fspec, int len)
{
	if (ft_strlen(str_num) - len >= 2 && fspec->min == 1
		&& fspec->width >= fspec->prec)
	{
		if (fspec->c == 'X')
		{
			str_num[0] = '0';
			str_num[1] = 'X';
		}	
		else
		{
			str_num[0] = '0';
			str_num[1] = 'x';
		}
	}
	else if (fspec->c == 'X')
		str_num = ft_strjoin_free2("0X", str_num);
	else
		str_num = ft_strjoin_free2("0x", str_num);
	fspec->hash = 0;
	return (str_num);
}

char	*manage_x(unsigned long long int arg_num, char *str_num, t_spec *fspec)
{
	int	i;
	int	len;

	i = ft_strlen(str_num);
	len = ft_strlen(str_num);
	if (fspec->prec > i)
		str_num = manage_u_prec(str_num, fspec, arg_num);
	if (arg_num == 0 && fspec->prec == 0)
	{
		free(str_num);
		str_num = ft_strdup("");
	}
	if (fspec->hash == 1 && arg_num != 0 && !hash_check(fspec, len, arg_num))
		str_num = manage_hash_x(str_num, fspec, len);
	i = ft_strlen(str_num);
	if (fspec->width >= i && fspec->width > 0)
	{
		i = fspec->width - ft_strlen(str_num);
		str_num = manage_u_width(str_num, fspec, i);
		str_num = hash_w_z(str_num, fspec, len, arg_num);
	}
	if (fspec->hash == 1 && arg_num != 0 && fspec->zero == 1
		&& fspec->prec == -1)
		str_num = manage_hash_x(str_num, fspec, len);
	return (str_num);
}

int	form_x(va_list *ap, t_spec *fspec)
{
	unsigned long long int	arg_num;
	char					*str_num;
	int						len;

	fspec->base = 16;
	len = 0;
	if (fspec->min == 1)
		fspec->zero = 0;
	arg_num = manage_u_mods(ap, fspec);
	str_num = ft_itoa_u(arg_num, fspec);
	str_num = manage_x(arg_num, str_num, fspec);
	ft_putstr(str_num);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}
