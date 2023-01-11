/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:09 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:16 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long int	manage_di_mods(va_list *ap, t_spec *fspec)
{
	if (fspec->mod == 2)
		return ((char)va_arg(*ap, int));
	else if (fspec->mod == 1)
		return ((short int)va_arg(*ap, int));
	else if (fspec->mod == 3)
		return ((long)va_arg(*ap, long int));
	else if (fspec->mod == 4)
		return (va_arg(*ap, long long int));
	else
		return ((int)va_arg(*ap, int));
}

unsigned long long int	manage_u_mods(va_list *ap, t_spec *fspec)
{
	if (fspec->mod == 2)
		return ((unsigned char)va_arg(*ap, unsigned int));
	else if (fspec->mod == 1)
		return ((unsigned short int)va_arg(*ap, unsigned int));
	else if (fspec->mod == 3)
		return ((unsigned long)va_arg(*ap, unsigned long int));
	else if (fspec->mod == 4)
		return (va_arg(*ap, unsigned long long int));
	else
		return ((unsigned int)va_arg(*ap, unsigned int));
}

long double	manage_f_mods(va_list *ap, t_spec *fspec)
{
	if (fspec->mod == 5)
		return ((long double)va_arg(*ap, long double));
	else
		return ((double)va_arg(*ap, double));
}

void	star_init(va_list *ap, t_spec *fspec)
{
	int	i;

	i = fspec->width;
	if (fspec->star_w == 1)
	{
		fspec->width = va_arg(*ap, int);
		if (i != 0)
			fspec->width = i;
		if (fspec->width < 0)
		{
			fspec->width *= -1;
			fspec->min = 1;
		}
	}	
	if (fspec->star_p == 1)
	{
		fspec->prec = va_arg(*ap, int);
		if (fspec->prec < 0)
			fspec->prec = -1;
	}	
}

void	reset_flags(t_spec *fspec)
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
}
