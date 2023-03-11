/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:49 by ajones            #+#    #+#             */
/*   Updated: 2023/03/11 17:10:04 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_line	*make_array_line(t_asm *assem, t_line *old)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		error_exit1(LINE_FAIL, NO_REF, assem);
	line->line = ft_strdup(old->line);
	line->next = NULL;
	line->num = 0;
	return (line);
}

/*
	This turns the t_line sturct into an array rather than a list so it can
	be referred to by index.
*/

t_line	**make_line_array(t_asm *assem)
{
	int		i;
	t_line	*old;
	t_line	**line;

	i = 0;
	old = assem->line;
	line = (t_line **)malloc(sizeof(t_line *) * (assem->line_count));
	if (!line)
		error_exit1(LINE_FAIL, NO_REF, assem);
	while (i < assem->line_count)
	{
		line[i] = make_array_line(assem, old);
		old = old->next;
		i++;
	}
	return (line);
}

/*
	Adds the line element to the end of the t_line list.
*/

void	append_line(t_asm *assem, t_line *line)
{
	t_line	*tmp;

	tmp = assem->line;
	while (assem->line->next)
		assem->line = assem->line->next;
	assem->line->next = line;
	assem->line = tmp;
}

t_line	*make_line(t_asm *assem, char *line, int line_num)
{
	t_line	*line_str;

	line_str = (t_line *)malloc(sizeof(t_line));
	if (!line_str)
		error_exit1(LINE_FAIL, NO_REF, assem);
	line_str->num = line_num;
	line_str->line = ft_strdup(line);
	line_str->next = NULL;
	return (line_str);
}

/*
	This will read line by line and save each line to the t_line struct. Once
	everything has been saved. It is also be saved as an array of t_line structs
	to make it easier to find lines by index. The original t_line struct will
	only be used to parse the name/comment and for the data to save everything
	to the array of t_line.
	
	End_line_space goes to parse_utils2.c, this checks whether the last line
	only contains whitespace. If it does, like the the original asm, the 
	program will compile.
	 
	If the last line is not whitespace, we check with Verify_newline
	to see if there is a newline at the end of the file. If one has not been
	found then, it will exit the program.
*/

void	read_file(t_asm *assem, char *file)
{
	int		fd;
	char	*line;
	t_line	*line_str;

	fd = open(file, O_RDONLY);
	line = NULL;
	if (fd == -1)
		error_exit1(ERR_FILE, NO_REF, assem);
	while (get_next_line(fd, &line) > 0)
	{
		line_str = make_line(assem, line, assem->line_count);
		if (!assem->line)
			assem->line = line_str;
		else
			append_line(assem, line_str);
		ft_strdel(&line);
		assem->line_count++;
	}
	close(fd);
	if (!assem->line)
		error_exit1(EMPTY, NO_REF, assem);
	if (!end_line_space(assem))
		verify_newline(assem, file);
	assem->l_array = make_line_array(assem);
}
