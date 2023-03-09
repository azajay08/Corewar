/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:15 by sam               #+#    #+#             */
/*   Updated: 2023/03/09 16:01:02 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** get_id:
** -
*/
static void	get_id(int ac, char **av, int i, t_player *player)
{
	char		*s;
	uint32_t	nbr;
	int			j;

	if (i + 1 >= ac)
		exit_vm("Invalid argument count.");
	s = av[i + 1];
	j = 0;
	while (s[j] && ft_isdigit(s[j]))
		j++;
	nbr = ft_atoi(s);
	if (nbr < 1 || nbr > MAX_PLAYERS)
		exit_vm("Invalid player ID.");
	player->id = nbr;
}

/*
** :
**
*/
static void	assign_player(t_vm *vm, t_player *player, int ret)
{
	int	i;

	i = 4;
	i += parse_file(player->name, &player->file[i], PROG_NAME_LENGTH);
	i += parse_size(&player->exec_size, player->file, i);
	i += parse_file(player->comment, &player->file[i], COMMENT_LENGTH);
	player->exec = ft_memalloc(ret - i);
	parse_file(player->exec, &player->file[i], player->exec_size);
	vm->player[player->id] = player;
}

/*
** add_first:
** -
*/
static int	add_first(t_vm *vm, int ac, char **av, t_player *player)
{
	int	i;
	int	ret;

	i = 1;
	while (i < ac)
	{
		if (av[i] && !ft_strcmp(av[i], "-n"))
			i += 2;
		else if (av[i])
		{
			ret = read_cor(av, i, player);
			assign_player(vm, player, ret);
			av[i] = NULL;
			return (0);
		}
		i++;
	}
	return (0);
}

/*
** do_player:
** -
*/
static int	do_player(int ac, char **av, t_vm *vm, unsigned int player_id)
{
	t_player	*player;
	int			i;
	int			ret;

	i = -1;
	player = ft_memalloc(sizeof(t_player));
	if (!player)
		exit_vm("Memory allocation failure in do_player.");
	while (++i < ac)
	{
		if (av[i] && (!ft_strcmp(av[i], "-n")))
		{
			get_id(ac, av, i, player);
			if (player->id == player_id)
			{
				ret = read_cor(av, i + 2, player);
				assign_player(vm, player, ret);
				ft_bzero(&av[i], sizeof(char *) * 3);
				return (0);
			}
			i += 2;
		}
	}
	player->id = player_id;
	return (add_first(vm, ac, av, player));
}

/*
** parse:
** -
*/
void	parse(int ac, char **av, t_vm *vm)
{
	uint32_t	player_id;

	player_id = 1;
	get_player_count(ac, av, &vm->player_count);
	while (player_id <= vm->player_count)
	{
		do_player(ac, av, vm, player_id);
		if (!&vm->player[player_id])
			exit_vm("Error during player parsing.");
		player_id++;
	}
}
