/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_arena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:00:10 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 12:44:19 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Prints the contents of the given line of memory in the arena.
*/
static void	print_memory_line(t_vm *vm, int i, uint8_t octets)
{
	int	j;

	j = -1;
	while (++j < octets)
		ft_printf("%.2x ", vm->arena[i + j]);
	ft_printf("\n");
}

/*
* - Prints the contents of the battle arena.
*/
void	print_arena(t_vm *vm)
{
	int	i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (vm->b_flag)
			ft_printf("%s%.4p : %s", BLKHB, i, RESET);
		else
			ft_printf("%.4p : ", i);
		if (vm->b_flag)
			debug_print_memory_line(vm, i, vm->print_octets);
		else
			print_memory_line(vm, i, vm->print_octets);
		i += vm->print_octets;
	}
}

/*
* - Prints the ID, weight, name and comment of each player.
*/
void	introduce_players(t_vm *vm)
{
	uint32_t	i;

	i = 1;
	ft_printf("Introducing contestants...\n", vm->player_count);
	while (i <= vm->player_count)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
		vm->player[i]->id, vm->player[i]->exec_size, \
		vm->player[i]->name, vm->player[i]->comment);
		i++;
	}
}

/*
* - Adds each players executable commands to the battle arena.
*/
static void	add_players_to_arena(t_player *player, t_vm *vm, size_t start)
{
	uint32_t	i;

	i = 0;
	if (player->exec_size <= 0)
		exit_vm("Error when adding players.");
	while (i < player->exec_size)
	{
		vm->arena[start + i] = player->exec[i];
		i++;
	}
}

/*
* - Initialises the contents of the arena.
*/
void	init_arena(t_vm *vm)
{
	size_t		starting_point;
	uint32_t	i;

	i = 0;
	starting_point = 0;
	ft_bzero(vm->arena, 4096);
	while (++i <= vm->player_count)
	{
		if (vm->player[i] == NULL)
			exit_vm("Invalid player.");
		add_players_to_arena(vm->player[i], vm, starting_point);
		starting_point += MEM_SIZE / vm->player_count;
	}
}
