/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_name.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:46 by ajones            #+#    #+#             */
/*   Updated: 2023/02/18 19:15:30 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_line	*get_comment(t_asm *assem, t_line *line, int start, int end)
{
	int	i;

	i = 0;
	assem->champ_com = ft_strnew(end);
	if (!assem->champ_com)
		error_exit1(INV_FILE, assem);
	while (i < end)
	{
		if (line->line[start] == '\0')
		{
			line = line->next;
			start = 0;
			continue ;
		}
		assem->champ_com[i] = line->line[start];
		i++;
		start++;
	}
	return (line);
}

t_line	*get_name(t_asm *assem, t_line *line, int start, int end)
{
	int	i;

	i = 0;
	assem->champ_name = ft_strnew(end);
	if (!assem->champ_name)
		error_exit1(INV_FILE, assem);
	while (i < end)
	{
		if (line->line[start] == '\0')
		{
			line = line->next;
			start = 0;
			continue ;
		}
		assem->champ_name[i] = line->line[start];
		i++;
		start++;
	}
	return (line);
}

t_line	*get_champ_cmd(t_asm *assem, t_line *line, char *cmd)
{
	int		i;
	int		start;
	int		end;
	t_line	*temp;

	i = cmd_str_check(assem, line->line, cmd) + 1;
	end = 0;
	start = i;
	temp = line;
	while (line->line[i] != '"' && line)
	{	
		if (line->line[i] == '\0')
		{
			line = line->next;
			i = 0;
			continue ;
		}
		end++;
		i++;
	}
	if (ft_strequ(cmd, NAME_CMD_STRING))
		line = get_name(assem, temp, start, end);
	else
		line = get_comment(assem, temp, start, end);
	return (line);
}

t_line	*get_name_comment(t_asm *assem, t_line *line)
{
	if (ft_strstr(line->line, NAME_CMD_STRING))
		line = get_champ_cmd(assem, line, NAME_CMD_STRING);
	else
		line = get_champ_cmd(assem, line, COMMENT_CMD_STRING);
	while (line->next)
	{
		if (assem->champ_com && assem->champ_name)
			break ;
		line = line->next;
		if (line_check(line->line))
			continue ;
		if (ft_strstr(line->line, NAME_CMD_STRING) && !assem->champ_name)
			line = get_champ_cmd(assem, line, NAME_CMD_STRING);
		else if (ft_strstr(line->line, COMMENT_CMD_STRING) && !assem->champ_com)
			line = get_champ_cmd(assem, line, COMMENT_CMD_STRING);
		else
			break ;
	}
	return (line);
}

t_line	*parse_header(t_asm *assem, t_line *line)
{
	while (line)
	{
		if (line_check(line->line))
			line = line->next;
		else if (ft_strstr(line->line, NAME_CMD_STRING)
			|| ft_strstr(line->line, COMMENT_CMD_STRING))
		{
			line = get_name_comment(assem, line);
			line = line->next;
			break ;
		}
		else
			break ;
	}
	verify_name_com(assem, line);
	return (line);
}
