/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:33:27 by zaz               #+#    #+#             */
/*   Updated: 2023/02/20 16:53:17 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H
/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define IND_SIZE				2
# define REG_SIZE				4
# define DIR_SIZE				REG_SIZE

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3

# define MAX_ARGS_NUMBER		4
# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024) // 4096
# define IDX_MOD				(MEM_SIZE / 8) // 512
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6) // 683?

# define COMMENT_CHAR			'#'
# define ALT_COMMENT_CHAR		';'
# define LABEL_CHAR				':'
# define DIRECT_CHAR			'%'
# define SEPARATOR_CHAR			','

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER				16

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
/*
**
*/
typedef char					t_arg_type;

# define T_REG					1
# define T_DIR					2
# define T_IND					4
# define T_LAB					8
/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define STATEMENT_MAX 			16

typedef struct s_header
{
	unsigned int				magic;
	char						prog_name[PROG_NAME_LENGTH + 1];
	unsigned int				prog_size;
	char						comment[COMMENT_LENGTH + 1];
}								t_header;

typedef struct s_op
{
	int							arg_num;
	int							arg_type[3];
	int							arg_type_code;
	int							size_t_dir;
	int							cycles;
	int							state_code;
	char						*state_name;
}								t_op;

static const t_op				g_op_tab[STATEMENT_MAX] = {
{
	.state_code = 0x01,
	.state_name = "live",
	.arg_num = 1,
	.arg_type = {T_DIR, 0, 0},
	.arg_type_code = 0,
	.size_t_dir = 0,
	.cycles = 10
},
{
	.state_code = 0x02,
	.state_name = "ld",
	.arg_num = 2,
	.arg_type = {T_DIR | T_IND, T_REG, 0},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 5
},
{
	.state_code = 0x03,
	.state_name = "st",
	.arg_num = 2,
	.arg_type = {T_REG, T_IND | T_REG, 0},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 5
},
{
	.state_code = 0x04,
	.state_name = "add",
	.arg_num = 3,
	.arg_type = {T_REG, T_REG, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 10
},
{
	.state_code = 0x05,
	.state_name = "sub",
	.arg_num = 3,
	.arg_type = {T_REG, T_REG, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 10
},
{
	.state_code = 0x06,
	.state_name = "and",
	.arg_num = 3,
	.arg_type = {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 6
},
{
	.state_code = 0x07,
	.state_name = "or",
	.arg_num = 3,
	.arg_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 6
},
{
	.state_code = 0x08,
	.state_name = "xor",
	.arg_num = 3,
	.arg_type = {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 6
},
{
	.state_code = 0x09,
	.state_name = "zjmp",
	.arg_num = 1,
	.arg_type = {T_DIR, 0, 0},
	.arg_type_code = 0,
	.size_t_dir = 1,
	.cycles = 20
},
{
	.state_code = 0x0a,
	.state_name = "ldi",
	.arg_num = 3,
	.arg_type = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 1,
	.cycles = 25
},
{
	.state_code = 0x0b,
	.state_name = "sti",
	.arg_num = 3,
	.arg_type = {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
	.arg_type_code = 1,
	.size_t_dir = 1,
	.cycles = 25
},
{
	.state_code = 0x0c,
	.state_name = "fork",
	.arg_num = 1,
	.arg_type = {T_DIR, 0, 0},
	.arg_type_code = 0,
	.size_t_dir = 1,
	.cycles = 800
},
{
	.state_code = 0x0d,
	.state_name = "lld",
	.arg_num = 2,
	.arg_type = {T_DIR | T_IND, T_REG, 0},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 10
},
{
	.state_code = 0x0e,
	.state_name = "lldi",
	.arg_num = 3,
	.arg_type = {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
	.arg_type_code = 1,
	.size_t_dir = 1,
	.cycles = 50
},
{
	.state_code = 0x0f,
	.state_name = "lfork",
	.arg_num = 1,
	.arg_type = {T_DIR, 0, 0},
	.arg_type_code = 0,
	.size_t_dir = 1,
	.cycles = 1000
},
{
	.state_code = 0x10,
	.state_name = "aff",
	.arg_num = 1,
	.arg_type = {T_REG, 0, 0},
	.arg_type_code = 1,
	.size_t_dir = 0,
	.cycles = 2
}
};

#endif