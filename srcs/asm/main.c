/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 15:13:07 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_prog_size(t_asm *assem)
{
	int	i;

	i = 0;
	while (i < assem->line_count)
	{
		assem->prog_size += assem->l_array[i]->num;
		i++;
	}
	if (assem->prog_size > CHAMP_MAX_SIZE)
		error_exit1(TOO_BIG, assem);
}

void	parse_champ(t_asm *assem)
{
	int	index;

	index = parse_header(assem);
	parse_labels(assem, index);
	parse_instructions(assem, index);
	get_prog_size(assem);
}

void	init_asm(t_asm *assem, char *file_input)
{
	int	len;

	len = ft_strlen(file_input) - 2;
	assem->filename = ft_strsub(file_input, 0, len);
	assem->filename = ft_strjoin_free1(assem->filename, ".cor");
	assem->line_count = 0;
	assem->state_code = 0;
	assem->prog_size = 0;
	assem->champ_name = NULL;
	assem->champ_com = NULL;
	assem->line = NULL;
	assem->l_array = NULL;
	assem->label = NULL;
	assem->state = NULL;
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
	write_to_cor(assem);
	free_asm(assem);
	// system("leaks asm");
	return (0);
}

/*
void	print_array(t_asm *assem)
{
	int	i;

	i = 0;
	while (i < assem->line_count)
	{
		ft_printf("\n%s (%i) bytes", assem->l_array[i]->line, assem->l_array[i]->num);
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
		ft_printf("Bool: %d \n", tmp->state);
		tmp = tmp->next;
	}
}
	// ft_printf("Champion Name:\n(%s)", assem->champ_name);
	// ft_printf("\nChampion Comment:\n(%s)\n\n", assem->champ_com);
	// print_array(assem);
	// print_labels(assem);
*/