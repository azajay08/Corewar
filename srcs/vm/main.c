/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:40 by ajones            #+#    #+#             */
/*   Updated: 2023/02/06 15:52:07 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_usage()
{
	ft_putstr("Usage: ./corewar ");
	ft_putstr("[filename.cor] ([filename.cor] [filename.cor]\n");
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		print_usage();
	ft_putstr(argv[1]); // just for compilation
	return (0);
}
