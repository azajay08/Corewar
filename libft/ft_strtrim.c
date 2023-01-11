/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 14:28:18 by ajones            #+#    #+#             */
/*   Updated: 2022/01/03 17:02:59 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spacecheck(int c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	return (0);
}

char	*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	if (!s)
		return (NULL);
	if (!*s)
		return (ft_strnew(0));
	i = 0;
	while ((ft_spacecheck(s[i])) && s[i] != '\0')
		i++;
	j = ft_strlen(s) - 1;
	while ((ft_spacecheck(s[j])) && j > i)
		j--;
	len = j - i + 1;
	str = ((char *)malloc(sizeof(char) * (len + 1)));
	if (!str)
		return (NULL);
	k = 0;
	while (i <= j)
		str[k++] = s[i++];
	str[k] = '\0';
	return (str);
}
