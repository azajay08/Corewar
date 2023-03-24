/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:15 by sam               #+#    #+#             */
/*   Updated: 2023/03/24 14:21:20 by swilliam         ###   ########.fr       */
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
	if (player->exec_size == 0 || player->exec_size > 682)
		exit_vm("Player executable code too big.");
	vm->player[player->id - 1] = player;
}

static void	identify_player(
t_vm *vm,
t_player *player,
char *input,
uint32_t id)
{
	int	ret;

	player->id = id;
	ret = read_cor(input, player);
	assign_player(vm, player, ret, input);
}

/*
* - Allocates a fresh player, giving it the ascending player ID and stores
*   the read .cor file data inside.
*/
static void	allocate_player(int ac, char **av, t_vm *vm, uint32_t player_id)
{
	t_player	*player;
	int			i;
	char		*ext;
	uint32_t	count;

	i = 0;
	count = 0;
	player = ft_memalloc(sizeof(t_player));
	if (!player)
		exit_vm("Memory allocation failure in allocate_player.");
	while (++i < ac && av[i])
	{
		ext = ft_strrchr(av[i], '.');
		if (ext && ft_strcmp(ext, ".cor") == 0)
		{
			if (++count == player_id)
			{
				identify_player(vm, player, av[i], player_id);
				return ;
			}
		}
		else
			if (!is_valid_input(av[i]))
				exit_vm("Incorrect usage.");
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
	if (vm->player_count == 0)
		exit_vm("No participants found.");
	while (++player_id <= vm->player_count)
	{
		allocate_player(ac, av, vm, player_id);
		if (!&vm->player[player_id - 1])
			exit_vm("Error during player parsing.");
	}
	read_n_flags(ac, av, vm);
}
