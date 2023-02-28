/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/02/28 03:51:16 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	print_array(t_asm *assem)
{
	int	i;

	i = 0;
	while (i < assem->line_count)
	{
		ft_printf("line %i:\n(%s)\n", i, assem->l_array[i]->line);
		i++;
	}
}

void	print_labels(t_asm *assem)
{
	t_label	*tmp;

	tmp = assem->label;
	while (tmp)
	{
		ft_printf("\nLabel: (%s)\nLine: (%i)\n", tmp->label_name, tmp->line_nb);
		tmp = tmp->next;
	}
}

void	parse_champ(t_asm *assem)
{
	int		index;

	index = parse_header(assem);
	parse_labels(assem, index);
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
	ft_printf("Champion Name:\n(%s)", assem->champ_name);
	ft_printf("\nChampion Comment:\n(%s)\n\n", assem->champ_com);
	print_array(assem);
	print_labels(assem);
	ft_putchar('\n');
	system("leaks asm");
	return (0);
}
