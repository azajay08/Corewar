/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:12:14 by sam               #+#    #+#             */
/*   Updated: 2023/03/21 13:03:00 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Checks whether the input is one of the valid usage flags.
*/
int	is_valid_input(char *string)
{
	if (ft_isnumber(string) || ft_strcmp(string, "-d") == 0 \
		|| ft_strcmp(string, "-dump") == 0 || ft_strcmp(string, "-n") == 0 \
		|| ft_strcmp(string, "-a") == 0)
		return (1);
	return (0);
}

/*
* - Reads the given amount of bytes.
*/
int	get_n_byte(uint32_t n, unsigned char *data, uint32_t idx)
{
	uint32_t	i;
	int			value;

	value = 0;
	i = 0;
	if (data)
	{
		while (i < n)
			value = (value * 0x100) + data[idx + i++];
	}
	return (value);
}

/*
* - Reads the given arguments, counting how many .cor files are provided.
*/
void	get_player_count(int ac, char **av, uint32_t *player_count)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_strstr(av[i], ".cor") != NULL)
			*player_count += 1;
		i++;
	}
}
