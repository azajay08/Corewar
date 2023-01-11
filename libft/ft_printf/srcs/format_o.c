/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:55 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:57 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_zero_o(char *str_num, t_spec *fspec)
{
	if (fspec->hash == 1)
	{
		free(str_num);
		str_num = ft_strdup("0");
	}
	else
	{
		free(str_num);
		str_num = ft_strdup("");
	}
	return (str_num);
}

char	*manage_hash_o(char *str_num, t_spec *fspec, int len)
{
	if (ft_strlen(str_num) - len >= 1 && fspec->zero == 1)
		str_num[0] = '0';
	else
		str_num = ft_strjoin_free2("0", str_num);
	return (str_num);
}

char	*manage_o(unsigned long long int arg_num, char *str_num, t_spec *fspec)
{
	int	i;
	int	len;

	i = ft_strlen(str_num);
	len = ft_strlen(str_num);
	if (fspec->prec > i)
		str_num = manage_u_prec(str_num, fspec, arg_num);
	if (arg_num == 0 && fspec->prec == 0)
		manage_zero_o(str_num, fspec);
	if (fspec->hash == 1 && arg_num != 0)
		str_num = manage_hash_o(str_num, fspec, len);
	i = ft_strlen(str_num);
	if (fspec->width >= i && fspec->width > 0)
	{
		i = fspec->width - ft_strlen(str_num);
		str_num = manage_u_width(str_num, fspec, i);
	}
	if (fspec->hash == 1 && arg_num != 0 && fspec->zero == 1
		&& fspec->prec == -1)
		str_num = manage_hash_o(str_num, fspec, len);
	return (str_num);
}

int	form_o(va_list *ap, t_spec *fspec)
{
	unsigned long long int	arg_num;
	char					*str_num;
	int						len;

	fspec->base = 8;
	len = 0;
	arg_num = manage_u_mods(ap, fspec);
	str_num = ft_itoa_u(arg_num, fspec);
	str_num = manage_o(arg_num, str_num, fspec);
	ft_putstr(str_num);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}
