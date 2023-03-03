/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 12:00:10 by sam               #+#    #+#             */
/*   Updated: 2023/03/03 12:15:41 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_arena(t_vm *vm)
{
	int	i;
	int	j;

	i = 0;
	while (i < MEM_SIZE)
	{
		j = -1;
		while (++j < 64)
			ft_printf("%02x ", vm->arena[i + j]);
		ft_printf("\n");
		i += j;
	}
}

static void	add_players_to_arena(t_player *player, t_vm *vm, size_t starting_point)
{
	uint32_t	i;

	i = 0;
	while (i < player->exec_size)
	{
		vm->arena[starting_point + i] = player->exec[i];
		i++;
	}

}

void	init_arena(t_vm *vm)
{
	t_player	*temp_player;
	size_t		starting_point;
	uint32_t	i;

	temp_player = vm->player;
	starting_point = 0;
	i = 0;
	while (++i < vm->player_count + 1)
	{
		add_players_to_arena(temp_player, vm, starting_point);
		temp_player = temp_player->next;
		starting_point += MEM_SIZE / vm->player_count;
	}
}
