/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:19 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:54:22 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_u_width(char *str, t_spec *fspec, int i)
{
	char	*add_str;
	int		s;

	s = 0;
	add_str = ft_strnew(i);
	while (i--)
	{
		if (fspec->prec == -1 && fspec->zero == 1 && fspec->min != 1)
			add_str[s++] = '0';
		else
			add_str[s++] = ' ';
	}
	str = join_str(add_str, str, fspec);
	return (str);
}

char	*manage_u_prec(char *str, t_spec *fspec, unsigned long long int arg_num)
{
	char	*add_str;
	int		i;
	int		z;

	z = 0;
	i = fspec->prec - ft_strlen(str);
	if (fspec->c == 'o' && fspec->hash == 1 && arg_num != 0 && fspec->zero != 1)
		i--;
	if (fspec->c == 'x' || fspec->c == 'X')
	{
		if (fspec->min == 1 && fspec->width >= fspec->prec && fspec->hash == 1
			&& arg_num != 0)
			i += 2;
	}
	add_str = ft_strnew(i);
	if (!add_str)
		return (NULL);
	while (i--)
		add_str[z++] = '0';
	str = ft_strjoin_free2(add_str, str);
	free(add_str);
	return (str);
}

char	*manage_u(unsigned long long int arg_num, char *str_num, t_spec *fspec)
{
	int	i;

	i = ft_strlen(str_num);
	if (fspec->prec > i)
		str_num = manage_u_prec(str_num, fspec, arg_num);
	if (arg_num == 0 && fspec->prec == 0)
	{
		free(str_num);
		str_num = ft_strdup("");
	}
	i = ft_strlen(str_num);
	if (fspec->width >= i && fspec->width > 0)
	{
		i = fspec->width - ft_strlen(str_num);
		str_num = manage_u_width(str_num, fspec, i);
	}
	return (str_num);
}

int	form_u(va_list *ap, t_spec *fspec)
{
	unsigned long long int	arg_num;
	char					*str_num;
	int						len;

	len = 0;
	arg_num = manage_u_mods(ap, fspec);
	str_num = ft_itoa_u(arg_num, fspec);
	str_num = manage_u(arg_num, str_num, fspec);
	ft_putstr(str_num);
	len = ft_strlen(str_num);
	free(str_num);
	return (len);
}
