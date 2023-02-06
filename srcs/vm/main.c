/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:40 by ajones            #+#    #+#             */
/*   Updated: 2023/02/06 15:21:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	print_usage(char *argv)
{
	ft_printf("%s", argv);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		print_usage(argv[1]);
	return (0);
}
