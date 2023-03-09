/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:40 by ajones            #+#    #+#             */
/*   Updated: 2023/03/09 14:29:17 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_usage(void)
{
	exit_vm("Usage: ./corewar champ1.cor (champ2.cor champ3.cor)");
}

int	main(int argc, char **argv)
{
	t_vm	vm;

	if (argc < 2)
		print_usage();
	ft_printf("%sInitialising data...%s\n", UGRN, RESET);
	init_vm(&vm);
	ft_printf("%sParsing assembled files...%s\n", UGRN, RESET);
	parse(argc, argv, &vm);
	ft_printf("%sIntroducing players...%s\n", UGRN, RESET);
	introduce_players(&vm);
	ft_printf("%sInitiating Corewar process...%s\n", UGRN, RESET);
	game_process(&vm);
	exit(EXIT_SUCCESS);
	return (0);
}
