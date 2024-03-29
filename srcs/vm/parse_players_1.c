/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:15 by sam               #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/27 15:44:47 by swilliam         ###   ########.fr       */
=======
/*   Updated: 2023/03/28 14:25:36 by ajones           ###   ########.fr       */
>>>>>>> c2a855f529d92832818b4f75f407947bc0488f9c
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

static int	is_valid_flag_nb(char *string, char *previous_string)
{
	if (ft_isnumber(string) && \
		(ft_strcmp(previous_string, "-n") != 0 && \
		ft_strcmp(previous_string, "-d") != 0 && \
		ft_strcmp(previous_string, "-dump") != 0))
		return (0);
	return (1);
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
				identify_player(vm, player, av[i], player_id);
		}
		else
			if (!is_valid_input(av[i]) || !is_valid_flag_nb(av[i], av[i - 1]))
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
	if (vm->player_count == 0 || vm->player_count > MAX_PLAYERS)
		exit_vm("No participants found.");
	while (++player_id <= vm->player_count)
	{
		allocate_player(ac, av, vm, player_id);
		if (!&vm->player[player_id - 1])
			exit_vm("Error during player parsing.");
	}
	read_n_flags(ac, av, vm);
}
