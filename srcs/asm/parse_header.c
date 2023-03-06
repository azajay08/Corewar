/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 16:24:46 by ajones            #+#    #+#             */
/*   Updated: 2023/03/06 16:32:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	get_comment(t_asm *assem, t_line *line, int start, int end)
{
	int	i;

	i = 0;
	assem->champ_com = ft_strnew(end);
	if (!assem->champ_com)
		error_exit1(COM_FAIL, assem);
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
}

void	get_name(t_asm *assem, t_line *line, int start, int end)
{
	int	i;

	i = 0;
	assem->champ_name = ft_strnew(end);
	if (!assem->champ_name)
		error_exit1(NAME_FAIL, assem);
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
}

t_line	*get_champ_cmd(t_asm *assem, t_line *line, t_line *temp, char *cmd)
{
	int		i;
	int		start;
	int		end;

	i = cmd_str_check(assem, line->line, cmd) + 1;
	end = 0;
	start = i;
	while (line && line->line[i] != '"')
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
	if (!line)
		error_exit1(INV_HDR, assem);
	if (ft_strequ(cmd, NAME_CMD_STRING))
		get_name(assem, temp, start, end);
	else
		get_comment(assem, temp, start, end);
	return (line);
}

t_line	*get_name_comment(t_asm *assem, t_line *line)
{
	t_line	*temp;

	temp = line;
	if (ft_strstr(line->line, NAME_CMD_STRING))
		line = get_champ_cmd(assem, line, temp, NAME_CMD_STRING);
	else
		line = get_champ_cmd(assem, line, temp, COMMENT_CMD_STRING);
	while (line->next)
	{
		if (assem->champ_com && assem->champ_name)
			break ;
		line = line->next;
		if (line_check(line->line))
			continue ;
		temp = line;
		if (ft_strstr(line->line, NAME_CMD_STRING) && !assem->champ_name)
			line = get_champ_cmd(assem, line, temp, NAME_CMD_STRING);
		else if (ft_strstr(line->line, COMMENT_CMD_STRING) && !assem->champ_com)
			line = get_champ_cmd(assem, line, temp, COMMENT_CMD_STRING);
		else
			break ;
	}
	return (line);
}

int	parse_header(t_asm *assem)
{
	t_line	*line;

	line = assem->line;
	while (line)
	{
		if (line_check(line->line))
			line = line->next;
		else if (ft_strstr(line->line, NAME_CMD_STRING)
			|| ft_strstr(line->line, COMMENT_CMD_STRING))
		{
			line = get_name_comment(assem, line);
			if (line->next)
				line = line->next;
			break ;
		}
		else
			break ;
	}
	verify_name_com(assem, line);
	return (line->num);
}
