/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 01:14:35 by aaronjones        #+#    #+#             */
/*   Updated: 2023/01/19 17:44:52 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_round(long double num, int i)
{
	long double	round_num;
	long double	dec;

	dec = 0.5;
	while (i > 0)
	{
		dec = dec / 10;
		i--;
	}
	if (num >= 0)
		round_num = num + dec;
	else
		round_num = num - dec;
	return (round_num);
}
