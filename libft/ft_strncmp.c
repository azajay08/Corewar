/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:15:42 by ajones            #+#    #+#             */
/*   Updated: 2021/11/08 15:38:01 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	a;

	a = 0;
	if (n == 0)
		return (0);
	while (s1[a] && s2[a] && a < (n - 1))
	{
		if (s1[a] != s2[a])
			return ((unsigned char) s1[a] - (unsigned char) s2[a]);
		a++;
	}
	return ((unsigned char) s1[a] - (unsigned char) s2[a]);
}
