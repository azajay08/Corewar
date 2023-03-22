/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:40 by ajones            #+#    #+#             */
/*   Updated: 2023/03/21 19:51:57 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - When the given input is incorrect, the correct program usage is printed.
*/
static void	print_usage(void)
{
	exit_vm("Usage:   ./corewar champ1.cor champ2.cor champ3.cor\n\
		Flags:\n\
		-dump (n): Prints the arena with 64 bytes per line at cycle n.\n\
		-d (n): Prints the arena with 32 bytes per line at cycle n.\n\
		-n (n): The next player will be given the ID n.\n\
		-a: Sets the a flag for the 'aff' statement command.\n\
		-b: Enables debug messages.\n");
}

/*
* corewar:
* -
*/
int	main(int argc, char **argv)
{
	t_vm	vm;

	if (argc < 2)
		print_usage();
	if (DEBUG == true)
		ft_printf("%sInitialising data...%s\n", UGRN, RESET);
	init_vm(&vm);
	if (DEBUG == true)
		ft_printf("%sParsing assembled files...%s\n", UGRN, RESET);
	parse(argc, argv, &vm);
	if (DEBUG == true)
		ft_printf("%sInitialising carriages...%s\n", UGRN, RESET);
	set_carriages(&vm);
	if (DEBUG == true)
		ft_printf("%sIntroducing players...%s\n", UGRN, RESET);
	introduce_players(&vm);
	if (DEBUG == true)
		ft_printf("%sInitiating Corewar carriage...%s\n", UGRN, RESET);
	game_process(&vm);
	exit(EXIT_SUCCESS);
	return (0);
}
