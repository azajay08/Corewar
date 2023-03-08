/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_to_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 02:23:35 by ajones            #+#    #+#             */
/*   Updated: 2023/03/08 21:22:50 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_comment(t_asm *assem, int fd)
{
	int		i;
	int		len;
	char	comment[COMMENT_LENGTH + 4];

	i = 0;
	len = ft_strlen(assem->champ_com);
	ft_bzero(comment, COMMENT_LENGTH + 4);
	while (i < len)
	{
		comment[i] = assem->champ_com[i];
		i++;
	}
	write(fd, comment, COMMENT_LENGTH + 4);
}

void	write_prog_size(t_asm *assem, int fd)
{
	write(fd, &((unsigned char *)&assem->prog_size)[3], 1);
	write(fd, &((unsigned char *)&assem->prog_size)[2], 1);
	write(fd, &((unsigned char *)&assem->prog_size)[1], 1);
	write(fd, &((unsigned char *)&assem->prog_size)[0], 1);
}

void	write_name(t_asm *assem, int fd)
{
	int		i;
	int		len;
	char	name[PROG_NAME_LENGTH + 4];

	i = 0;
	len = ft_strlen(assem->champ_name);
	ft_bzero(name, PROG_NAME_LENGTH + 4);
	while (i < len)
	{
		name[i] = assem->champ_name[i];
		i++;
	}
	write(fd, name, PROG_NAME_LENGTH + 4);
}

void	write_header(int fd)
{
	int	magic;

	magic = (int)COREWAR_EXEC_MAGIC;
	write(fd, &((unsigned char *)&magic)[3], 1);
	write(fd, &((unsigned char *)&magic)[2], 1);
	write(fd, &((unsigned char *)&magic)[1], 1);
	write(fd, &((unsigned char *)&magic)[0], 1);
}

void	write_to_cor(t_asm *assem)
{
	int	fd;

	fd = open(assem->filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	write_header(fd);
	write_name(assem, fd);
	write_prog_size(assem, fd);
	write_comment(assem, fd);
	write_exec_code(assem, fd);
}
