/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 13:04:04 by ajones            #+#    #+#             */
/*   Updated: 2021/11/16 13:09:39 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*s;
	unsigned char	byt;
	size_t			i;

	s = (char *)b;
	byt = (unsigned char)c;
	i = 0;
	while (i < len)
	{
		s[i] = byt;
		i++;
	}
	return (b);
}
