/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 13:15:01 by ajones            #+#    #+#             */
/*   Updated: 2021/11/11 14:46:09 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	a;
	int	b;

	if (*needle == '\0')
		return ((char *)haystack);
	a = 0;
	while (haystack[a] != '\0')
	{
		b = 0;
		while (haystack[a + b] == needle[b] && needle[b] != '\0')
		{
			b++;
		}
		if (needle[b] == '\0')
			return ((char *)haystack + a);
		a++;
	}
	return (NULL);
}
