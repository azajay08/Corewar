/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:42:16 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:55:14 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_numlen(int n)
{
	int	i;

	i = 1;
	if (n < 0)
	{
		i++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		tmp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmp = n;
	i = ft_numlen(n);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	if (n < 0)
		tmp = n * -1;
	str[i] = '\0';
	i--;
	str[i] = tmp % 10 + '0';
	while (tmp >= 10 && i > 0)
	{
		tmp = tmp / 10;
		i--;
		str[i] = tmp % 10 + '0';
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
