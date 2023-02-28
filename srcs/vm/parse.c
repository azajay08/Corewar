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

#include "../../includes/vm.h"

int	get_n_byte(unsigned int n, unsigned char *data, unsigned int idx)
{
	unsigned int	i;
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

void	get_player_count(int ac, char **av, unsigned int *player_count)
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

void	check_magic(unsigned char *data)
{
	if (get_n_byte(4, data, 0) != COREWAR_EXEC_MAGIC) //check the first 4 bytes of the file corresspond to corewar magic macro
		ft_printf("ERROR_4\n");
}

int	read_cor(char **av, int i, t_player *player)
{
	int	fd;
	int	ret;

	fd = open(av[i], O_RDONLY);
	ret = read(fd, player->file, MEM_SIZE);
	check_magic(player->file);
	close(fd);
	return (ret);
}

int	parse_file(unsigned char *player_data, unsigned char *data, int len)
{
	ft_memcpy(player_data, data, len);
	return (len + 4); // len + NULL
}

int	parse_size(unsigned int *exec_size, unsigned char *data, unsigned int i)
{
	*exec_size = get_n_byte(4, data, i);
	return (4);
}

void	get_id(int ac, char **av, int i, t_player *player)
{
	char	*s;
	unsigned int	nbr;
	int	j;

	if (i + 1 >= ac)
		ft_printf("ERROR_2\n");
	s = av[i + 1];
	j = 0;
	while (s[j] && ft_isdigit(s[j]))
		j++;
	nbr = ft_atoi(s);
	if (nbr < 1 || nbr > MAX_PLAYERS)
		ft_printf("ERROR_3\n");
	player->id = nbr;
}

void	assign_player(t_player *player, int ret, unsigned int player_id)
{
	int i;

	i = 4;
	i += parse_file(player->name, &player->file[i], PROG_NAME_LENGTH); // get name
	i += parse_size(&player->exec_size, player->file, i); // get exec size
	i += parse_file(player->comment, &player->file[i], COMMENT_LENGTH); //get comment
	player->exec = ft_memalloc(ret - i);
	parse_file(player->exec, &player->file[i], player->exec_size); // get exec code
	player->id = player_id;
	ft_printf("ID: %u\n", player->id);
	ft_printf("Name: %s\n", player->name);
	ft_printf("Exec_size: %u\n", player->exec_size);
	ft_printf("Comment: %s\n", player->comment);
/* 	unsigned int j = 0;
	ft_printf("Exec_code: ");
	while (j < player->exec_size)
	{
		ft_printf("%hhX ", player->exec[j]);
		j++;
	}*/
	ft_printf("\n\n");
}

int	add_first(int ac, char **av, t_player *player, unsigned int player_id)
{
	int	i;
	int ret;

	i = 1;
	while (i < ac)
	{
		if (av[i] && !ft_strcmp(av[i], "-n"))
			i += 2;
		else if (av[i])
		{
			ret = read_cor(av, i, player);
			assign_player(player, ret, player_id);
			av[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}

int	do_player(int ac, char **av, t_player *player, unsigned int player_id)
{
	int	i;
	int ret;

	i = 0;
	while (i < ac)
	{
		if (av[i] && (!ft_strcmp(av[i], "-n")))
		{
			get_id(ac, av, i, player);
			if (player->id == player_id)
			{
				ret = read_cor(av, i + 2, player);
				assign_player(player, ret, player_id);
				ft_bzero(&av[i], sizeof(char *) * 3);
				return (0);
			}
			i += 2;
		}
		i++;
	}
	return (add_first(ac, av, player, player_id));
}

void	parse(int ac, char **av, t_player *players, t_vm *vm)
{
	unsigned int player_id;
	int i;

	player_id = 1;
	i = 1;
	get_player_count(ac, av, &vm->player_count);
	init_players(players, vm->player_count);
	while (player_id <= vm->player_count)
	{
		do_player(ac, av, &players[player_id], player_id);
		if (!&players[player_id])
			ft_printf("ERROR_1\n");
		player_id++;
	}
}
