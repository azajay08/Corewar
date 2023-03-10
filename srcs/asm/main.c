/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 03:17:36 by ajones            #+#    #+#             */
/*   Updated: 2023/03/10 23:11:54 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
	Gets the executable code size.
*/

void	get_prog_size(t_asm *assem)
{
	int	i;

	i = 0;
	while (i < assem->line_count)
	{
		assem->prog_size += assem->l_array[i]->num;
		i++;
	}
}

/*
	Parse_champ sorts out the order of the parsing. The index will return
	the index of the line that is just after the name/comment.
*/

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
	assem->lex_index = 0;
	assem->champ_name = NULL;
	assem->champ_com = NULL;
	assem->line = NULL;
	assem->l_array = NULL;
	assem->label = NULL;
	assem->state = NULL;
}

/*
	Verify_filename goes to verify.c. It checks whether the file input
	is a valid.
	
	Init_asm is is just for initialising the t_asm struct.

	Read_file goes to read_file.c, this will open the input file, read it
	line by line, then will save each line to the t_line struct so it can be
	referred to later on. Eventually the lines will be saved as an array of
	line using the t_linestruct.
	
	Parse_champ will deal with all the parsing of the file. It will verify
	everything is in the correct format, then it will assign values to the 
	respective structs, ready for the writing phase.
	
	write_to_cor goes to write_to_cor.c. This is a function that will
	sort the order of writing bytes to the output file.

	Free_asm goes to free.c. This is will free all of the structs that have
	been used. All heads of the structs have been saved in the main t_asm
	which makes it easier to free them all in one place.
*/

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
	return (0);
}
