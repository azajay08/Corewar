/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:12:14 by sam               #+#    #+#             */
/*   Updated: 2023/03/15 17:13:00 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** get_n_byte:
** - Reads the given amount of bytes.
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
** get_player_count:
** - Reads the given arguments, counting how many .cor files are provided.
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

/*
** get_bit_pair:
** - Gets the n th pair of bits from a byte.
** - Example:
**   - Byte '90' is 10010000 in binary.
**   - 1st pair = 10, 2nd pair = 01, 3rd pair = 00, 4th pair = 00.
*/
int8_t get_bit_pair(u_int8_t byte, u_int8_t nth_pair)
{
	if (nth_pair == 1)
		return ((byte >> 6) & 3);
	else if (nth_pair == 2)
		return ((byte >> 4) & 3);
	else if (nth_pair == 3)
		return ((byte >> 2) & 3);
	else if (nth_pair == 4)
		return (byte & 3);
	return (-1);
}
