/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:05:59 by ajones            #+#    #+#             */
/*   Updated: 2022/01/03 17:05:50 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int		wcount;

	wcount = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s != c && *s != '\0')
			wcount++;
		while (*s != c && *s != '\0')
			s++;
	}
	return (wcount);
}

static int	ft_wlen(char const *s, char c)
{
	int		len;

	len = 0;
	while (*s == c)
		s++;
	while (*s != c && *s != '\0')
	{
		s++;
		len++;
	}
	return (len);
}

static void	ft_free_all(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	str = NULL;
}

static void	split_str(char **str, char const *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (i < ft_wcount(s, c))
	{
		k = 0;
		str[i] = ft_strnew(ft_wlen(&s[j], c) + 1);
		if (!str[i])
		{
			ft_free_all(str, i);
			return ;
		}
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j] != '\0')
			str[i][k++] = s[j++];
		str[i][k] = '\0';
		i++;
	}
}

char	**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;

	if (!s)
		return (NULL);
	i = ft_wcount(s, c);
	str = (char **)malloc(sizeof(*str) * (i + 1));
	if (!str)
		return (NULL);
	str[i] = NULL;
	split_str(str, s, c);
	return (str);
}
