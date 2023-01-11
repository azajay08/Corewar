/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:53:38 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:53:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	manage_char_flags(t_spec *fspec, char c)
{
	int	add_count;

	add_count = fspec->width;
	if (fspec->min != 0)
	{
		ft_putchar(c);
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
			if (fspec->zero == 1)
				ft_putchar('0');
			else
				ft_putchar(' ');
		}	
		ft_putchar(c);
	}
	return (add_count);
}

int	form_c(va_list *ap, t_spec *fspec)
{
	char	c;
	int		add_count;

	c = va_arg(*ap, int);
	add_count = 0;
	if (fspec->width != 0 || fspec->min != 0)
		add_count = manage_char_flags(fspec, c);
	else
	{
		ft_putchar(c);
		add_count = 1;
	}
	return (add_count);
}
