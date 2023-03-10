/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:53 by ajones            #+#    #+#             */
/*   Updated: 2023/03/09 17:28:53 by swilliam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../libft/includes/libft.h"
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
# define INV_FILE	"ERROR! Invalid File!\n"
# define INV_HDR	"ERROR! Invalid name or comment!\n"
# define INV_STATE	"ERROR! Invalid statement!\n"
# define LONG_NAME	"ERROR! Name too long!\n"
# define LONG_COM	"ERROR! Comment too long!\n"
# define INSTRUCT	"ERROR! No instructions found!\n"
# define NO_ARGS	"ERROR! No statement arguments found!\n"
# define ARG_COUNT	"ERROR! Incorrect argument count!\n"
# define COMMA		"ERROR! Comma at the end of the line!\n"
# define ARG_TYPE	"ERROR! Incorrect argument type!\n"
# define ARG_STR	"ERROR! Failed to create argument string!\n"
# define TOO_BIG	"ERROR! Executable code size too large!\n"
# define ARG_ERR	"ERROR! Incorrect argument input!\n"
# define INV_LBL	"ERROR! No matching label!\n"
# define LAST_LINE	"ERROR! No newline at end of file!\n"

typedef struct s_asm
{
	int				state_code;
	int				line_count;
	int				prog_size;
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
	int				state_code;
	int				arg_count;
	int				label;
	int				index;
	unsigned char	result;
	int				arg_val[3];
	char			**args;
	struct s_state	*next;
}					t_state;

int		main(int argc, char **argv);

/*
	Parsing & Reading
*/
int		arg_value(char *arg);
int		line_check(char *line);
int		comma_at_end(char *line);
int		parse_header(t_asm *assem);
int		end_line_space(t_asm *assem);
int		line_has_comment(char *line);
int		is_label(t_asm *assem, int index);
int		byte_length(t_asm *assem, int type);
int		statement_label(char *line, int start);
int		is_statement(t_asm *assem, char *state);
int		duplicate_label(t_asm *assem, char *str);
int		get_byte_count(t_asm *assem, char **args);
int		cmd_str_check(t_asm *assem, char *line, char *cmd);
int		line_has_statement(t_asm *assem, int index, char *line);
char	*remove_comments(char *line);
char	get_arg_result(t_asm *assem, char **args);
void	parse_arguments(t_asm *assem);
void	read_file(t_asm *assem, char *file);
void	label_check(t_asm *assem, int index);
void	parse_labels(t_asm *assem, int index);
void	parse_instructions(t_asm *assem, int index);
void	append_statement(t_asm *assem, t_state *statement);
t_state	*make_statement(t_asm *assem, int index);

/*
	Verifying
*/

void	check_reg_arg(t_asm *assem, char *arg);
void	check_dir_arg(t_asm *assem, char *arg);
void	check_ind_arg(t_asm *assem, char *arg);
void	verify_filename(char *filename);
void	verify_newline(t_asm *assem, char *file);
void	verify_name_com(t_asm *assem, t_line *line);
void	verify_arguments(t_asm *assem, t_state *state);

/*
	Writing
*/

void	write_to_cor(t_asm *assem);
void	write_exec_code(t_asm *assem, int fd);

/*
	Errors & Freeing
*/

void	free_asm(t_asm *assem);
void	error_exit(char *exit_str);
void	error_exit1(char *exit_str, t_asm *assem);

#endif