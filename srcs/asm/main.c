/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/02/10 23:12:08 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_map(t_asm *assem)
{
	t_line	*tmp;

	tmp = assem->line;
	while (tmp)
	{
		ft_putstr(tmp->line);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}

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
	read_file(assem, argv[1]);
	parse_champ(assem);
	// print_map(assem);
	ft_printf("Champion Name:\n%s",assem->champ_name);
	ft_putchar('\n');
	// system("leaks asm");
	return (0);
}
