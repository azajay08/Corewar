/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:53 by ajones            #+#    #+#             */
/*   Updated: 2023/02/25 21:13:48 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
# include "op.h"
# include "op_table.h"

# define USAGE		"Usage: ./asm [filename.s]\n"
# define EXT_S		"Invalid file! Input file must have [.s] extension\n\n"
# define ASSEM		"ERROR! Memory allocation of t_asm failed!\n"
# define LINE_FAIL	"ERROR! Memory allocation of t_line failed!\n"
# define LBL_FAIL	"ERROR! Memory allocation of t_label failed!\n"
# define LBL_NAME	"ERROR! Failed to create label name\n"
# define ERR_FILE	"ERROR! Unable to open file!\n"
# define INV_FILE	"ERROR! Inavlid File!\n"
# define LONG_NAME	"ERROR! Name too long\n"
# define LONG_COM	"ERROR! Comment too long\n"

typedef struct s_asm
{
	char			*filename;
	char			*champ_name;
	char			*champ_com;
	struct s_line	*line;
	struct s_label	*label;
}					t_asm;

typedef struct s_label
{
	int				line_nb;
	char			*label_name;
	struct s_label	*next;
}					t_label;

int		main(int argc, char **argv);

/*
	Initialising
*/

void	init_asm(t_asm *assem, char *file_input);

/*
	Errors
*/

void	error_exit(char *exit_str);
void	error_exit1(char *exit_str, t_asm *assem);

/*
	Reading functions
*/

void	read_file(t_asm *assem, char *file);

/*
	Freeing functions
*/
void	free_asm(t_asm *assem);

/*
	Parsing & parsing tools
*/

void	verify_name_com(t_asm *assem, t_line *line);
void	parse_labels(t_asm *assem, t_line *head);
int		line_check(char *line);
int		cmd_str_check(t_asm *assem, char *line, char *cmd);
t_line	*parse_header(t_asm *assem, t_line *line);

#endif