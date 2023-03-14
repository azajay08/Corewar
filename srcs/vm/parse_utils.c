/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:12:14 by sam               #+#    #+#             */
/*   Updated: 2023/03/06 14:44:43 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** :
**
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
** :
**
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
** Gets the n th pair of bits from a byte
** example byte '90' is 10010000 in binary
** 1st pair = 10, 2nd pair = 01, 3rd pair = 00, 4th pair = 00
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
