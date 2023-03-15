/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:50:15 by swilliam          #+#    #+#             */
/*   Updated: 2023/03/15 17:45:51 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** ft_isnumber:
** - Evaluates whether the given string only contains digits.
*/
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

/*
** set_dump_cycle:
** - When the -d flag is used, the output is printed with 32 octets per line.
** - When the -dump flag is used, the output is printed with 64 octets per line.
** - The value given after the above flags determines at which cycle the arena
**   is printed.
*/
int	set_dump_cycle(t_vm *vm, char *input, char *value)
{
	if (!ft_isnumber(value))
		exit_vm("Invalid dump value.");
	vm->dump = ft_atoi(value);
	if (vm->dump < 0)
		exit_vm("Invalid dump cycle.");
	if (ft_strlen(input) == 2)
		vm->print_octets = 32;
	else
		vm->print_octets = 64;
	return (2);
}

/*
** set_player_order:
** - When the -n flag is used, the value given after it determines which
**   id the next player will have.
*/
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
