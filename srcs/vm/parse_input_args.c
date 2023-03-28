/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:50:15 by swilliam          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/03/27 15:35:55 by swilliam         ###   ########.fr       */
=======
/*   Updated: 2023/03/28 14:25:40 by ajones           ###   ########.fr       */
>>>>>>> c2a855f529d92832818b4f75f407947bc0488f9c
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Returns the ID of the given .cor file name.
*/
static uint8_t	find_player_id(t_vm *vm, char *input)
{
	uint8_t	i;

	i = 0;
	while (++i <= vm->player_count)
	{
		if (ft_strcmp(vm->player[i - 1]->input, input) == 0)
			return (vm->player[i - 1]->id);
	}
	return (0);
}

/*
* - When the -d flag is used, the output is printed with 32 octets per line.
* - When the -dump flag is used, the output is printed with 64 octets per line.
* - The value given after the above flags determines at which cycle the arena
*   is printed.
*/
int	set_dump_cycle(t_vm *vm, char *input, char *value)
{
	if (!ft_isnumber(value))
		exit_vm("Incorrect usage.");
	vm->dump = ft_atoi(value);
	if (vm->dump < 0 || vm ->dump > 2147483647)
		exit_vm("Incorrect usage.");
	if (ft_strlen(input) == 2)
		vm->print_octets = 64;
	else
		vm->print_octets = 32;
	return (2);
}

/*
* - Reads the given input arguments, checking for flags.
*/
void	read_flags(int ac, char **av, t_vm *vm)
{
	int		i;
	char	*ext;

	i = 0;
	while (++i < ac)
	{
		if (!is_valid_input(av[i]))
		{
			ext = ft_strrchr(av[i], '.');
			if (ext && ft_strcmp(ext, ".cor") != 0)
				exit_vm("Incorrect usage.");
		}
		if (av[i] && ft_strncmp(av[i], "-dump", 2) == 0)
		{
			if (vm->dump >= 0 || !av[i + 1])
				exit_vm("Incorrect usage.");
			i += set_dump_cycle(vm, av[i], av[i + 1]);
		}
		if (av[i] && ft_strcmp(av[i], "-a") == 0 && vm->a_flag == false)
			vm->a_flag = true;
		if (av[i] && ft_strcmp(av[i], "-b") == 0 && vm->b_flag == false)
			vm->b_flag = true;
		if (av[i] && ft_strcmp(av[i], "-f") == 0 && vm->f_flag == false)
			vm->f_flag = true;
	}
}

/*
* - When the -n flag is used, the value given after it determines which
*   id the next player will have.
*/
void	set_player_order(t_vm *vm, char *input_id, t_player *player)
{
	uint8_t		to_id;
	uint8_t		from_id;
	t_player	*temp_player;

	temp_player = NULL;
	if (!ft_isnumber(input_id))
		exit_vm("Incorrect usage.");
	to_id = (uint8_t)ft_atoi(input_id);
	if (to_id < 1 || to_id > vm->player_count)
		exit_vm("Incorrect usage.");
	from_id = player->id;
	temp_player = vm->player[to_id - 1];
	vm->player[to_id - 1] = vm->player[from_id - 1];
	vm->player[from_id - 1] = temp_player;
	vm->player[from_id - 1]->id = from_id;
	vm->player[to_id - 1]->id = to_id;
}

/*
* Reads the input arguments, and when an -n is met, the next player is
* assigned the given ID and swapped with the player already existing there.
*/
void	read_n_flags(int ac, char **av, t_vm *vm)
{
	int	i;
	int	player_id;

	i = 0;
	player_id = 0;
	while (++i < ac)
	{
		if (av[i] && ft_strcmp(av[i], "-n") == 0)
		{
			if (i + 2 >= ac)
				exit_vm("Incorrect usage.");
			player_id = (int)find_player_id(vm, av[i + 2]) - 1;
			if (player_id < 0)
				exit_vm("Error during player order setting.");
			set_player_order(\
				vm, av[i + 1], vm->player[player_id]);
		}
	}
}
