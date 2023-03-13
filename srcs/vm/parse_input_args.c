/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:50:15 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/13 18:08:19 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	ft_isnumber(char *string)
{
	int	i;

	i = -1;
	while (string[++i])
	{
		if (!ft_isdigit(string[i]))
			return (0);
	}
	return (1);
}

int	set_dump_cycle(t_vm *vm, char *input, char *value)
{
	if (!ft_isnumber(value))
		exit_vm("Invalid dump value.");
	vm->cycle_dump = ft_atoi(value);
	if (vm->cycle_dump < 0)
		exit_vm("Invalid dump cycle.");
	if (ft_strlen(input) == 2)
		vm->print_octets = 32;
	else
		vm->print_octets = 64;
	return (2);
}

void	set_player_order(
	t_player *player,
	char *input_id)
{
	if (!ft_isnumber(input_id))
		exit_vm("Invalid player ID value given with -n flag.");
	player->id = ft_atoi(input_id);
	if (player->id < 1 || player->id > MAX_PLAYERS)
		exit_vm("Invalid player ID value given with -n flag.");
}
