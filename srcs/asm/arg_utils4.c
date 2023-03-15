/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 02:10:56 by ajones            #+#    #+#             */
/*   Updated: 2023/03/15 03:39:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	atoi_limit_neg(char *arg)
{
	int		i;
	char	*ll_min;

	ll_min = ft_strdup("-9223372036854775808");
	i = 0;
	while (i < MIN_LEN)
	{
		if (arg[i] > ll_min[i])
		{
			free(ll_min);
			return (-1);
		}
		i++;	
	}
	free(ll_min);
	return (ft_atoi(arg));
}

int	atoi_limit_pos(char *arg)
{
	int		i;
	char	*ll_max;

	ll_max = ft_strdup("9223372036854775807");
	i = 0;
	while (i < MAX_LEN)
	{
		if (arg[i] > ll_max[i])
		{
			free(ll_max);
			return (-1);
		}
		i++;	
	}
	free(ll_max);
	return (ft_atoi(arg));
}

/*
	First we check with atoi_limit to see if the argument's string length is
	bigger than the string length of what would be the long long max/min
	string length. If it is bigger, then we know it is beyond the limits and
	correct value can be returned without having to go through the calculations
	of ft_atoi. If the length is the same, then we need to check carefully
	what the value is. If the arguments length is smaller, then we simply 
	use ft_atoi.

	MIN_LEN = The string length of LLONG_MIN
	MAX_LEN = the string length of LLONG_MAX

	The limtits have to be checked by string lengths and char values becuase 
	if the number is out of range, it cannot be dealt with. If these checks
	are not performed and the number is out of range, ft_atoi would return a 
	value that has cycled back round from the MIN or MAX.
*/

int	atoi_limit(char *arg)
{
	int	arg_len;

	arg_len = ft_strlen(arg);
	if (arg[0] == '-')
	{
		if (arg_len > MIN_LEN)
			return (0);
		if (arg_len == MIN_LEN)
			return (atoi_limit_neg(arg));
	}
	else
	{
		if (arg_len > MAX_LEN)
			return (-1);
		if (arg_len == MAX_LEN)
			return (atoi_limit_pos(arg));
	}
	return (ft_atoi(arg));
}
