/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:13 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:54:16 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_width_str(t_spec *fspec, char *print_str, int len)
{
	char	*str;
	int		i;
	int		l;

	i = 0;
	l = len;
	if (fspec->width >= len)
		l = fspec->width;
	str = ft_strnew(l);
	if (!str)
		return (NULL);
	while (fspec->width-- > len)
	{
		if (fspec->zero == 1 && fspec->min == 0)
			str[i] = '0';
		else
			str[i] = ' ';
		i++;
	}
	if (fspec->min == 1)
		print_str = ft_strjoin_free1(print_str, str);
	else
		print_str = ft_strjoin_free2(str, print_str);
	free(str);
	return (print_str);
}

char	*manage_prec_str(t_spec *fspec, char *print_str, int len)
{	
	int		n;
	char	*str;

	if (fspec->prec <= len)
		str = ft_strsub(print_str, 0, fspec->prec);
	else
		str = ft_strsub(print_str, 0, len);
	free(print_str);
	n = ft_strlen(str);
	str = manage_width_str(fspec, str, n);
	return (str);
}

int	form_s(va_list *ap, t_spec *fspec)
{
	int		len;
	char	*arg_str;
	char	*print_str;

	arg_str = va_arg(*ap, char *);
	if (!arg_str)
		print_str = ft_strdup("(null)");
	else
		print_str = ft_strdup(arg_str);
	len = ft_strlen(print_str);
	if (fspec->min != 0 || fspec->width != 0 || fspec->prec != -1)
	{
		if (fspec->prec != -1)
			print_str = manage_prec_str(fspec, print_str, len);
		else
			print_str = manage_width_str(fspec, print_str, len);
	}
	len = ft_strlen(print_str);
	ft_putstr(print_str);
	free(print_str);
	return (len);
}
