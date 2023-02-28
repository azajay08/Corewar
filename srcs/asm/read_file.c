/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:57:49 by ajones            #+#    #+#             */
/*   Updated: 2023/02/28 03:06:11 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_line	*make_array_line(t_asm *assem, t_line *old)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		error_exit1(LINE_FAIL, assem);
	line->line = ft_strdup(old->line);
	line->next = NULL;
	line->num = 0;
	return (line);
}

t_line	**make_line_array(t_asm *assem)
{
	int		i;
	t_line	*old;
	t_line	**line;

	i = 0;
	old = assem->line;
	line = (t_line **)malloc(sizeof(t_line *) * (assem->line_count));
	if (!line)
		error_exit1(LINE_FAIL, assem);
	while (i < assem->line_count)
	{
		line[i] = make_array_line(assem, old);
		old = old->next;
		i++;
	}
	return (line);
}

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
		error_exit1(LINE_FAIL, assem);
	line_str->num = line_num;
	line_str->line = ft_strdup(line);
	line_str->next = NULL;
	return (line_str);
}

void	read_file(t_asm *assem, char *file)
{
	int		fd;
	int		line_num;
	char	*line;
	t_line	*line_str;

	line_num = 0;
	fd = open(file, O_RDONLY);
	line = NULL;
	if (fd == -1)
		error_exit1(ERR_FILE, assem);
	while (get_next_line(fd, &line) > 0)
	{
		line_str = make_line(assem, line, line_num);
		if (!assem->line)
			assem->line = line_str;
		else
			append_line(assem, line_str);
		ft_strdel(&line);
		line_num++;
	}
	close(fd);
	assem->line_count = line_num;
	assem->l_array = make_line_array(assem);
}
