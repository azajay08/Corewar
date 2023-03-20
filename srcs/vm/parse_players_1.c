/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:15 by sam               #+#    #+#             */
/*   Updated: 2023/03/20 18:47:16 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Stores the .cor file data inside the player struct
*/
static void	assign_player(t_vm *vm, t_player *player, int ret, char *input)
{
	int	i;

	i = 4;
	i += parse_file(player->name, &player->file[i], PROG_NAME_LENGTH);
	i += parse_size(&player->exec_size, player->file, i);
	i += parse_file(player->comment, &player->file[i], COMMENT_LENGTH);
	player->exec = ft_memalloc(ret - i);
	parse_file(player->exec, &player->file[i], player->exec_size);
	player->input = input;
	vm->player[player->id] = player;
}

/*
* - Allocates a fresh player, giving it the ascending player ID and stores
*   the read .cor file data inside.
*/
static void	allocate_player(int ac, char **av, t_vm *vm, uint32_t player_id)
{
	t_player	*player;
	int			i;
	int			ret;
	char		*ext;
	uint32_t	count;

	i = -1;
	count = 0;
	player = ft_memalloc(sizeof(t_player));
	if (!player)
		exit_vm("Memory allocation failure in do_player.");
	while (++i < ac && av[i])
	{
		ext = ft_strrchr(av[i], '.');
		if (ext && ft_strcmp(ext, ".cor") == 0)
		{
			if (++count == player_id)
			{
				player->id = player_id;
				ret = read_cor(av, i, player);
				assign_player(vm, player, ret, av[i]);
				return ;
			}
		}
	}
}

/*
* - Parses the input until each player is assigned their id and data.
* - Once all players are assigned put in ascending order, the -n flags are read
*   to assign a custom ID.
*/
void	parse(int ac, char **av, t_vm *vm)
{
	uint32_t	player_id;

	player_id = 0;
	read_flags(ac, av, vm);
	get_player_count(ac, av, &vm->player_count);
	while (++player_id <= vm->player_count)
	{
		allocate_player(ac, av, vm, player_id);
		if (!&vm->player[player_id])
			exit_vm("Error during player parsing.");
	}
	read_n_flags(ac, av, vm);
}
