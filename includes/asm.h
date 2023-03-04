/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:53 by ajones            #+#    #+#             */
/*   Updated: 2023/03/04 20:56:41 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "op.h"
# include "op_table.h"
# include <stdbool.h>

# define USAGE		"Usage: ./asm [filename.s]\n"
# define EXT_S		"Invalid file! Input file must have [.s] extension\n\n"
# define ASSEM		"ERROR! Memory allocation of t_asm failed!\n"
# define LINE_FAIL	"ERROR! Memory allocation of t_line failed!\n"
# define LBL_FAIL	"ERROR! Memory allocation of t_label failed!\n"
# define STATE_FAIL	"ERROR! Memory allocation of t_state failed!\n"
# define NAME_FAIL	"ERROR! Memory allocation of champion name failed!\n"
# define COM_FAIL	"ERROR! Memory allocation of champion comment failed!\n"
# define LBL_NAME	"ERROR! Failed to create label name\n"
# define ERR_FILE	"ERROR! Unable to open file!\n"
# define INV_FILE	"ERROR! Inavlid File!\n"
# define INV_HDR	"ERROR! Inavlid name or comment!\n"
# define INV_STATE	"ERROR! Inavlid statement!\n"
# define LONG_NAME	"ERROR! Name too long!\n"
# define LONG_COM	"ERROR! Comment too long!\n"
# define INSTRUCT	"ERROR! No instructions found!\n"

typedef struct s_asm
{
	int				line_count;
	char			*filename;
	char			*champ_name;
	char			*champ_com;
	struct s_line	*line;
	struct s_line	**l_array;
	struct s_label	*label;
	struct s_state	*state;
}					t_asm;

typedef struct s_label
{
	int				line_nb;
	bool			state;
	char			*label_name;
	struct s_label	*next;
}					t_label;

typedef struct s_state
{
	int				byte_count;
	int				state_num;
	int				index;
	int				label;
	int				arg_count;
	t_arg_type		arg_type[3];
	struct s_state	*next;
	
}					t_state;

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
	verifying
*/
void	verify_name_com(t_asm *assem, t_line *line);
void	verify_filename(char *filename);

/*
	Parsing & parsing tools
*/


int		line_check(char *line);
int		cmd_str_check(t_asm *assem, char *line, char *cmd);
int		parse_header(t_asm *assem);
int		duplicate_label(t_asm *assem, char *str);
int		statement_label(char *line, int start);
void	parse_labels(t_asm *assem, int index);
void	parse_instructions(t_asm *assem, int index);

#endif