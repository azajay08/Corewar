/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/01/22 19:26:40 by ajones           ###   ########.fr       */
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
	t_asm	*assem;
	
	if (argc != 2 || !verify_filename(argv[1]))
		error_exit(USAGE);
	assem = (t_asm *)malloc(sizeof(t_asm));
	if (!assem)
		error_exit(ASSEM);
	init_asm(assem, argv[1]);
	return (0);
}
