/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:46 by ajones            #+#    #+#             */
/*   Updated: 2023/02/10 23:09:54 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


/*
	mess right now, but just testing what is needed with the name and comments.
	it works but need to clean up and be 100% on what is needed
*/

// void	get_champ_com(t_asm *assem, t_line *line)
// {
	
// }

void	get_champ_name(t_asm *assem, t_line *line)
{
	int	start;
	int	end;
	int	i;
	t_line	*temp;

	start = 0;
	end = 0;
	temp = line;
	i = 0;
	if (ft_strstr(line->line, NAME_CMD_STRING))
	{
		temp = line;
		line->line = ft_strchr(line->line, '"');
		line->line++;
		while (line->line[i] != '"')
		{	
			if (line->line[i] == '\0')
			{
				line = line->next;
				i = 0;
				continue;
			}
			end++;
			i++;
		}
		i = 0;
		line = temp;
		assem->champ_name = ft_strnew(end);
		while (end)
		{
			if (line->line[start] == '\0')
			{
				line = line->next;
				start = 0;
				continue;
			}
			assem->champ_name[i] = line->line[start];
			i++;
			start++;
			end--;
		}
	}
}

void	parse_champ(t_asm *assem)
{
	t_line	*line;

	line = assem->line;
	while (!assem->champ_name && line)
	{
		get_champ_name(assem, line);
		line = line->next;
	}
	if (!assem->champ_name)
		error_exit1(INV_FILE, assem);
	// while (!assem->champ_com && line)
	// {
	// 	get_champ_com(assem, line);
	// 	line = line->next;
	// }
	// if (!assem->champ_com)
	// 	error_exit1(INV_FILE, assem);
	
}