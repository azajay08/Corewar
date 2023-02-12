/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:46 by ajones            #+#    #+#             */
/*   Updated: 2023/02/12 05:11:23 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"


/*
	mess right now, but just testing what is needed with the name and comments.
	it works but need to clean up and be 100% on what is needed
*/

t_line	*get_champ_com(t_asm *assem, t_line *line)
{
	int	start;
	int	end;
	int	i;
	t_line	*temp;

	start = 0;
	end = 0;
	temp = line;
	i = 0;
	if (!ft_strchr(line->line, '"'))
		error_exit1(INV_FILE, assem);
	while (line->line[i] != '"')
		i++;
	i++;
	start = i;
	while (line->line[i] != '"' && line)
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
	assem->champ_com = ft_strnew(end);
	while (end)
	{
		if (line->line[start] == '\0')
		{
			line = line->next;
			start = 0;
			continue;
		}
		assem->champ_com[i] = line->line[start];
		i++;
		start++;
		end--;
	}
	return(line);
}

t_line	*get_champ_name(t_asm *assem, t_line *line)
{
	int	start;
	int	end;
	int	i;
	t_line	*temp;

	start = 0;
	end = 0;
	temp = line;
	i = 0;
	if (!ft_strchr(line->line, '"'))
		error_exit1(INV_FILE, assem);
	while (line->line[i] != '"')
		i++;
	i++;
	start = i;
	while (line->line[i] != '"' && line)
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
	if (!line)
		error_exit1(INV_FILE, assem);
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
	return(line);
}

t_line	*get_name_com(t_asm *assem, t_line *line)
{
	if (ft_strstr(line->line, NAME_CMD_STRING))
		line = get_champ_name(assem, line);
	else
		line = get_champ_com(assem, line);
	if (line->next)
	{
		line = line->next;
		if (!assem->champ_name)
			line = get_champ_name(assem, line);
		else
			line = get_champ_com(assem, line);
	}
	return (line);
}

void	parse_champ(t_asm *assem)
{
	t_line	*line;

	line = assem->line;
	while (line)
	{
		if (line->line[0] == COMMENT_CHAR || line->line[0] == ALT_COMMENT_CHAR)
			line = line->next;
		else if (ft_strstr(line->line, NAME_CMD_STRING) 
		|| ft_strstr(line->line, COMMENT_CMD_STRING))
		{
			line = get_name_com(assem, line);
			line = line->next;
			break ;
		}
		else
			break ;
	}
	// ft_printf("line: %s\n", line->line);
	if (!assem->champ_name || !assem->champ_com || !line)
		error_exit1(INV_FILE, assem);
}