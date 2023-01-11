/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:49 by ajones            #+#    #+#             */
/*   Updated: 2022/09/08 17:10:14 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'L')
		return (1);
	else
		return (0);
}

int	is_flag(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == '.' || c == ' '
		|| ft_isdigit(c) || is_mod(c) || c == '*')
		return (1);
	else
		return (0);
}

int	is_form_spec(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'o'
		|| c == 'u' || c == 'x' || c == 'X' || c == 'f' || c == '%')
		return (1);
	else
		return (0);
}

int	form_spec_id(va_list *ap, t_spec *fspec)
{
	if (fspec->c == 'c')
		return (form_c(ap, fspec));
	if (fspec->c == 's')
		return (form_s(ap, fspec));
	if (fspec->c == 'i' || fspec->c == 'd')
		return (form_di(ap, fspec));
	if (fspec->c == 'u')
		return (form_u(ap, fspec));
	if (fspec->c == 'x' || fspec->c == 'X')
		return (form_x(ap, fspec));
	if (fspec->c == 'o')
		return (form_o(ap, fspec));
	if (fspec->c == 'p')
		return (form_p(ap, fspec));
	if (fspec->c == 'f')
		return (form_f(ap, fspec));
	if (fspec->c == '%')
		return (form_perc(fspec));
	return (0);
}

int	read_spec(char const *format, va_list *ap, t_spec *fspec)
{
	int		i;
	int		f;
	int		add_count;

	i = 1;
	f = 0;
	add_count = 0;
	init_fspec(fspec);
	fspec->flag_str = ft_strnew(100);
	while (format[i] && !is_form_spec(format[i]))
	{
		if (is_flag(format[i]))
			fspec->flag_str[f++] = format[i];
		i++;
	}
	if (ft_strcmp(fspec->flag_str, "") != 0)
		init_flags(fspec);
	else
		free(fspec->flag_str);
	fspec->c = format[i];
	star_init(ap, fspec);
	add_count = form_spec_id(ap, fspec);
	return (add_count);
}
