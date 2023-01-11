/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:36:21 by ajones            #+#    #+#             */
/*   Updated: 2021/12/27 17:32:05 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	targ;
	int		i;

	targ = (char)c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == targ)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == targ)
		return ((char *)(s + i));
	return (NULL);
}
