/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:31:51 by ajones            #+#    #+#             */
/*   Updated: 2021/11/11 18:42:27 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	a;
	size_t	b;
	size_t	len;
	size_t	i;

	a = 0;
	b = 0;
	i = ft_strlen(dst) + ft_strlen(src);
	len = dstsize - ft_strlen(dst) - 1;
	while (dst[a] != '\0')
		a++;
	if (a < dstsize)
	{
		while (src[b] != '\0' && b < len)
		{
			dst[a + b] = src[b];
			b++;
		}
	}
	dst[a + b] = '\0';
	if (dstsize < ft_strlen(dst))
		i = ft_strlen(src) + dstsize;
	return (i);
}
