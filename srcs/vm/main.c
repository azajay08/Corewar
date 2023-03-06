/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:40 by ajones            #+#    #+#             */
/*   Updated: 2023/03/06 14:19:31 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_usage(void)
{
	exit_vm("Usage: ./corewar champ1.cor (champ2.cor champ3.cor)");
}

int	main(int argc, char **argv)
{
	t_vm		vm;

	if (argc < 2)
		print_usage();
	init_vm(&vm);
	ft_printf("Parsing assembled files...\n");
	parse(argc, argv, &vm);
	ft_printf("Initiating Corewar process...\n");
	game_process(&vm);
	exit(EXIT_SUCCESS);
	return (0);
}
