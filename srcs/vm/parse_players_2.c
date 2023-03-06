/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlahin <tlahin@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:28:36 by tlahin            #+#    #+#             */
/*   Updated: 2023/02/15 15:28:37 by tlahin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** :
**
*/
int	read_cor(char **av, int i, t_player *player)
{
	int	fd;
	int	ret;

	fd = open(av[i], O_RDONLY);
	ret = read(fd, player->file, MEM_SIZE);
	if (get_n_byte(4, player->file, 0) != COREWAR_EXEC_MAGIC)
		exit_vm("Invalid magic header.");
	close(fd);
	return (ret);
}

/*
** :
**
*/
int	parse_file(unsigned char *player_data, unsigned char *data, int len)
{
	ft_memcpy(player_data, data, len);
	return (len + 4); // len + NULL
}

/*
** :
**
*/
int	parse_size(uint32_t *exec_size, unsigned char *data, uint32_t i)
{
	*exec_size = get_n_byte(4, data, i);
	return (4);
}
