/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_neg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 10:52:47 by ajones            #+#    #+#             */
/*   Updated: 2022/09/05 10:52:51 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_neg(double num)
{
	long long int	*bin_num;
	char			sign;

	bin_num = (long long int *)&num;
	sign = (char)(*bin_num >> 63);
	if (sign == 0)
		return (0);
	else
		return (1);
}
