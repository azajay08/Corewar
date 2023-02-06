/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/02/06 15:18:26 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static void	verify_filename(char *filename)
{
	if (!ft_strequ(ft_strrchr(filename, '.'), ".s"))
	{
		ft_putstr(EXT_S);
		error_exit(USAGE);
	}
}

int	main(int argc, char **argv)
{
	t_asm	*assem;
	
	if (argc != 2)
		error_exit(USAGE);
	verify_filename(argv[1]);
	assem = (t_asm *)malloc(sizeof(t_asm));
	if (!assem)
		error_exit(ASSEM);
	init_asm(assem, argv[1]);
	return (0);
}
