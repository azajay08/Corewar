/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_players_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 13:49:15 by sam               #+#    #+#             */
/*   Updated: 2023/03/06 14:23:04 by sam              ###   ########.fr       */
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
	int i;

	i = 4;
	i += parse_file(player->name, &player->file[i], PROG_NAME_LENGTH); // get name
	i += parse_size(&player->exec_size, player->file, i); // get exec size
	i += parse_file(player->comment, &player->file[i], COMMENT_LENGTH); //get comment
	player->exec = ft_memalloc(ret - i);
	parse_file(player->exec, &player->file[i], player->exec_size); // get exec code
	ft_printf("ID: %u\n", player->id);
	ft_printf("Name: %s\n", player->name);
	ft_printf("Exec_size: %u\n", player->exec_size);
	ft_printf("Comment: %s\n", player->comment);
	// unsigned int j = 0;
	// ft_printf("Exec_code: ");
	// while (j < player->exec_size)
	// {
	// 	ft_printf("%hhX ", player->exec[j]);
	// 	j++;
	// }
	ft_printf("\n");
	vm->player[player->id] = player;
}

/*
** add_first:
** -
*/
static int	add_first(t_vm *vm, int ac, char **av, t_player *player)
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

	i = 0;
	player = ft_memalloc(sizeof(t_player));
	if (!player)
		exit_vm("Memory allocation failure in do_player.");
	while (i < ac)
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
		i++;
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
	uint32_t 	player_id;

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
