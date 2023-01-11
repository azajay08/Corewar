/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_percent.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:07 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:54:10 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	manage_perc_flags(t_spec *fspec)
{
	int	add_count;

	add_count = fspec->width;
	if (fspec->min != 0)
	{
		ft_putchar('%');
		if (fspec->width > 1)
			while (fspec->width-- > 1)
				ft_putchar(' ');
		else
		add_count = 1;
	}
	else
	{
		while (fspec->width-- > 1)
		{
			if (fspec->zero != 0)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}
		ft_putchar('%');
	}
	return (add_count);
}

int	form_perc(t_spec *fspec)
{
	int	add_count;

	add_count = 0;
	if (fspec->width != 0 || fspec->zero != 0 || fspec->min != 0)
		add_count = manage_perc_flags(fspec);
	else
	{
		ft_putchar('%');
		add_count = 1;
	}
	return (add_count);
}
