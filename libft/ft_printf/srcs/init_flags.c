/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:36 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:54:39 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	is_flag_init(char c)
{
	if (c == '#' || c == '-' || c == '+' || c == '0' || c == ' ')
		return (1);
	else
		return (0);
}

void	init_mods(t_spec *fspec)
{
	int	i;

	i = 0;
	while (!is_mod(fspec->flag_str[i]))
		i++;
	if (fspec->flag_str[i] == 'L')
		fspec->mod = 5;
	if (fspec->flag_str[i] == 'l')
	{
		fspec->mod = 3;
		if (fspec->flag_str[i + 1] == 'l')
			fspec->mod = 4;
	}
	if (fspec->flag_str[i] == 'h')
	{
		fspec->mod = 1;
		if (fspec->flag_str[i + 1] == 'h')
			fspec->mod = 2;
	}
}

void	init_prec(t_spec *fspec)
{
	char	*nb_str;
	int		i;
	int		n;

	fspec->prec = 0;
	n = 0;
	i = 0;
	nb_str = ft_strnew(20);
	while (fspec->flag_str[i] != '.')
		i++;
	i++;
	if (fspec->flag_str[i] == '*')
	{
		fspec->star_p = 1;
		i++;
	}
	if (ft_isdigit(fspec->flag_str[i]))
	{
		while (ft_isdigit(fspec->flag_str[i]))
			nb_str[n++] = fspec->flag_str[i++];
		fspec->prec = ft_atoi(nb_str);
	}
	ft_strdel(&nb_str);
	if (is_mod(fspec->flag_str[i]))
		init_mods(fspec);
}

void	init_width(t_spec *fspec, int i)
{
	char	*nb_str;
	int		n;

	n = 0;
	nb_str = ft_strnew(20);
	if (fspec->flag_str[i] == '*')
	{
		fspec->star_w = 1;
		i++;
	}
	if (ft_isdigit(fspec->flag_str[i]))
	{
		while (ft_isdigit(fspec->flag_str[i]))
			nb_str[n++] = fspec->flag_str[i++];
		fspec->width = ft_atoi(nb_str);
	}
	ft_strdel(&nb_str);
	if (fspec->flag_str[i] == '.')
		init_prec(fspec);
	else if (is_mod(fspec->flag_str[i]))
		init_mods(fspec);
	free(fspec->flag_str);
}

void	init_flags(t_spec *fspec)
{
	int	i;

	i = 0;
	reset_flags(fspec);
	while (is_flag_init(fspec->flag_str[i]))
	{
		if (fspec->flag_str[i] == '-')
			fspec->min = 1;
		if (fspec->flag_str[i] == '+')
			fspec->plus = 1;
		if (fspec->flag_str[i] == '#')
			fspec->hash = 1;
		if (fspec->flag_str[i] == ' ')
			fspec->space = 1;
		if (fspec->flag_str[i] == '0')
			fspec->zero = 1;
		i++;
	}
	init_width(fspec, i);
}
