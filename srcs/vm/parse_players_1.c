/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:15 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:26:57 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Stores the .cor file data inside the player struct
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
* -
*/
static void	add_first(t_vm *vm, int ac, char **av, t_player *player)
{
	int			i;
	uint32_t	count;
	int			ret;
	char		*ext;

	i = 0;
	count = 0;
	while (++i < ac)
	{
		if (av[i])
		{
			ext = ft_strrchr(av[i], '.');
			if (ext && ft_strcmp(ext, ".cor") == 0)
			{
				count++;
				if (count == player->id)
				{
					ret = read_cor(av, i, player);
					assign_player(vm, player, ret);
					av[i] = NULL;
					return ;
				}
			}
		}
	}
}

/*
* -
*/
static void	do_player(int ac, char **av, t_vm *vm, uint32_t player_id)
{
	t_player	*player;
	int			i;
	int			ret;

	i = -1;
	player = ft_memalloc(sizeof(t_player));
	if (!player)
		exit_vm("Memory allocation failure in do_player.");
	while (++i < ac && av[i])
	{
		if (av[i + 2] && ft_strcmp(av[i], "-n") == 0)
		{
			set_player_order(player, av[i + 1]);
			if (player->id == player_id)
			{
				ret = read_cor(av, i + 2, player);
				assign_player(vm, player, ret);
				return ;
			}
		}
		if (av[i + 1] && ft_strncmp(av[i], "-dump", 2) == 0 && vm->dump < 0)
			i += set_dump_cycle(vm, av[i], av[i + 1]);
	}
	player->id = player_id;
	add_first(vm, ac, av, player);
}

/*
* - Parses the input until each player is assigned their id and data.
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
