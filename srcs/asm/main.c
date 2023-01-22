/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/01/22 18:10:42 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	verify_filename(char *filename)
{
	if (!ft_strequ(ft_strrchr(filename, '.'), ".s"))
	{
		ft_putstr(EXT_S);
		return (0);
	}
	return (1);
}

void	error_exit(char *exit_str)
{
	ft_putstr(exit_str);
	exit(1);
}

int	main(int argc, char **argv)
{
	if (argc != 2 || !verify_filename(argv[1]))
		error_exit(USAGE);
	return (0);
}
