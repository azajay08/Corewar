/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:55:40 by ajones            #+#    #+#             */
/*   Updated: 2023/01/17 20:34:17 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

long double	ft_power_double(long double base, int power)
{
	int			i;
	long double	n;

	i = 0;
	n = 1.0;
	while (i < power)
	{
		n *= base;
		i++;
	}
	return (n);
}
