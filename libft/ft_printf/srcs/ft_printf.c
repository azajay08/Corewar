/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:31 by ajones            #+#    #+#             */
/*   Updated: 2022/10/07 17:33:31 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	print_c(char str, t_spec *fspec)
{
	ft_putchar(str);
	fspec->total++;
	return (fspec->total);
}

void	init_fspec(t_spec *fspec)
{
	fspec->min = 0;
	fspec->plus = 0;
	fspec->zero = 0;
	fspec->mod = 0;
	fspec->hash = 0;
	fspec->width = 0;
	fspec->prec = -1;
	fspec->space = 0;
	fspec->star_w = 0;
	fspec->star_p = 0;
	fspec->c = '\0';
	fspec->base = 10;
	fspec->min_over = 0;
	fspec->zero_over = 0;
	fspec->flag_str = NULL;
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	t_spec	fspec;
	int		i;

	i = -1;
	va_start(ap, format);
	fspec.total = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			if (is_form_spec(format[i + 1]) || is_flag(format[i + 1]))
				fspec.total += read_spec(&format[i++], &ap, &fspec);
			while (is_flag(format[i]))
				i++;
			if (!is_form_spec(format[i]) && !is_flag(format[i]))
				print_c(format[i], &fspec);
		}
		else
			print_c(format[i], &fspec);
	}
	va_end(ap);
	return (fspec.total);
}
