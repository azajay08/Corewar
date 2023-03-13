/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:00:10 by sam               #+#    #+#             */
/*   Updated: 2023/03/10 13:07:01 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** print_arena:
** - Prints the contents of the battle arena.
*/
void	print_arena(t_vm *vm)
{
	t_process	*temp_process;
	int			i;
	int			j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = -1;
		ft_printf("%.4p : ", i);
		while (++j < 64)
		{
			temp_process = vm->processes;
			while (temp_process)
			{
				if (i + j == temp_process->pos && !temp_process->executed)
				{
					ft_printf("%s", REDB);
					break ;
				}
				temp_process = temp_process->next;
			}
			ft_printf("%02x%s ", vm->arena[i + j], RESET);
		}
		ft_printf("\n");
		i += j;
	}
}

/*
** introduce_players:
** - Prints the ID, weight, name and comment of each player.
*/
void	introduce_players(t_vm *vm)
{
	uint32_t	i;

	i = 1;
	ft_printf("Introducing our %d contestants!\n", vm->player_count);
	while (i <= vm->player_count)
	{
		ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", \
		vm->player[i]->id, vm->player[i]->exec_size, \
		vm->player[i]->name, vm->player[i]->comment);
		i++;
	}
	ft_putchar('\n');
}

/*
** add_players_to_arena:
** - Adds each players executable commands to the battle arena.
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
** init_arena:
** - Initialises the contents of the arena.
*/
void	init_arena(t_vm *vm)
{
	size_t		starting_point;
	uint32_t	i;

	i = 0;
	starting_point = 0;
	while (++i <= vm->player_count)
	{
		if (vm->player[i] == NULL)
			exit_vm("Invalid player.");
		add_players_to_arena(vm->player[i], vm, starting_point);
		starting_point += MEM_SIZE / vm->player_count;
	}
}
