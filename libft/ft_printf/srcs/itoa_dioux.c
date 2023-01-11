/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_dioux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:54:42 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:54:45 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_numlen_base_u(unsigned long long int num, int base)
{
	int	len;

	len = 1;
	while (num / base > 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

void	ft_base_u(char *str, unsigned long long int num, int len, t_spec *fspec)
{
	char	*numl_str;
	int		i;

	if (fspec->c == 'X')
		numl_str = "0123456789ABCDEF";
	else
		numl_str = "0123456789abcdef";
	i = num % fspec->base;
	if (num >= fspec->base)
	{
		str[len--] = numl_str[i];
		num = num / fspec->base;
		ft_base_u(str, num, len, fspec);
	}
	else
		str[len] = numl_str[i];
}

char	*ft_itoa_u(unsigned long long int num, t_spec *fspec)
{
	char	*str;
	int		i;

	if (fspec->base < 2 || fspec->base > 16)
		return (NULL);
	i = ft_numlen_base_u(num, fspec->base);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	str[i--] = '\0';
	ft_base_u(str, num, i, fspec);
	return (str);
}

int	numlen_sign(long long int num)
{
	int	i;

	i = 1;
	if (num == -9223372036854775807 - 1)
	{
		i = 19;
		return (i);
	}
	if (num < 0)
		num = num * -1;
	while (num >= 10)
	{
		num = num / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_signed(long long int num)
{
	char				*str;
	long long int		tmp;
	int					i;

	i = numlen_sign(num);
	tmp = num;
	if (num == -9223372036854775807 - 1)
		return (str = ft_strdup("9223372036854775808"));
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	if (num < 0)
		tmp = num * -1;
	str[i] = '\0';
	i--;
	str[i] = tmp % 10 + '0';
	while (tmp >= 10 && i > 0)
	{
		tmp = tmp / 10;
		i--;
		str[i] = tmp % 10 + '0';
	}
	return (str);
}
