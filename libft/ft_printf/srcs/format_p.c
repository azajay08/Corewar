/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:00 by ajones            #+#    #+#             */
/*   Updated: 2022/09/13 19:43:03 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*manage_p_prec(char *str, t_spec *fspec, int len)
{
	char	*add_str;
	int		z;
	int		i;

	z = 0;
	i = fspec->prec - len;
	add_str = ft_strnew(i);
	while (i--)
		add_str[z++] = '0';
	str = ft_strjoin_free2(add_str, str);
	free(add_str);
	return (str);
}

char	*manage_p(char *str, t_spec *fspec)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(str);
	if (fspec->prec > len)
		str = manage_p_prec(str, fspec, len);
	if (ft_strequ(str, "0") && fspec->prec == 0)
	{
		free(str);
		str = ft_strdup("");
	}
	str = ft_strjoin_free2("0x", str);
	len = ft_strlen(str);
	if (fspec->width > len)
	{
		if (fspec->prec == -1 && fspec->zero == 1 && fspec->min != 1)
			str[1] = '0';
		i = fspec->width - ft_strlen(str);
		str = manage_u_width(str, fspec, i);
		if (fspec->prec == -1 && fspec->zero == 1 && fspec->min != 1)
			str[1] = 'x';
	}
	return (str);
}

int	form_p(va_list *ap, t_spec *fspec)
{
	void	*ptr;
	char	*str;
	int		len;

	fspec->base = 16;
	len = 0;
	ptr = va_arg(*ap, void *);
	str = ft_itoa_u((uintptr_t)ptr, fspec);
	str = manage_p(str, fspec);
	ft_putstr(str);
	len = ft_strlen(str);
	free(str);
	return (len);
}
