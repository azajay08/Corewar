/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 13:32:05 by ajones            #+#    #+#             */
/*   Updated: 2021/11/10 15:40:45 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	targ;
	int		i;

	targ = (char)c;
	i = 0;
	while (s[i] != '\0')
		i++;
	while (s[i] != targ && i != 0)
		i--;
	if (s[i] == targ)
		return ((char *)(s + i));
	if (s[i] == '\0' && c == '\0')
		return (NULL);
	return (0);
}
