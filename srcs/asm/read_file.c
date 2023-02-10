/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:49 by ajones            #+#    #+#             */
/*   Updated: 2023/02/10 16:17:34 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	append_line(t_asm *assem, t_line *line)
{
	t_line	*tmp;

	tmp = assem->line;
	while (assem->line->next)
		assem->line = assem->line->next;
	assem->line->next = line;
	assem->line = tmp;
}

t_line	*make_line(t_asm *assem, char *line)
{
	t_line	*line_str;

	line_str = (t_line *)malloc(sizeof(t_line));
	if (!line_str)
		error_exit1(LINE_FAIL, assem);
	line_str->line = ft_strdup(line);
	line_str->next = NULL;
	return (line_str);
}

void	read_file(t_asm *assem, char *file)
{
	int		fd;
	char	*line;
	t_line	*line_str;
	
	line = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error_exit1(ERR_FILE, assem);
	while (get_next_line(fd, &line) > 0)
	{
		line_str = make_line(assem, line);
		if (!assem->line)
			assem->line = line_str;
		else
			append_line(assem, line_str);
		ft_strdel(&line);
	}
}
