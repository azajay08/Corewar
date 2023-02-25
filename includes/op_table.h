/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_table.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:31:19 by ajones            #+#    #+#             */
/*   Updated: 2023/02/25 20:52:16 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_TABLE_H
# define OP_TABLE_H

# include "op.h"

# define LIVE 			1
# define LD 			2
# define ST 			3
# define ADD 			4
# define SUB			5
# define AND 			6
# define OR 			7
# define XOR 			8
# define ZJMP 			9
# define LDI 			10
# define STI 			11
# define FORK 			12
# define LLD 			13
# define LLDI 			14
# define LFORK 			15
# define AFF 			16

# define STATEMENT_MAX 	16

typedef char			t_arg_type;

typedef struct s_op
{
	int					state_code;
	char				*state_name;
	int					arg_num;
	t_arg_type			arg_type[3];
	int					cycles;
	int					arg_type_code;
	int					size_t_dir;
}						t_op;

static const t_op		g_op_tab[17] = {
{1, "live", 1, {T_DIR}, 10, 0, 0},
{2, "ld", 2, {T_DIR | T_IND, T_REG}, 5, 1, 0},
{3, "st", 2, {T_REG, T_IND | T_REG}, 5, 1, 0},
{4, "add", 3, {T_REG, T_REG, T_REG}, 10, 1, 0},
{5, "sub", 3, {T_REG, T_REG, T_REG}, 10, 1, 0},
{6, "and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6,
	1, 0},
{7, "or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6,
	1, 0},
{8, "xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 6,
	1, 0},
{9, "zjmp", 1, {T_DIR}, 20, 0, 1},
{10, "ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 25,
	1, 1},
{11, "sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 25,
	1, 1},
{12, "fork", 1, {T_DIR}, 800, 0, 1},
{13, "lld", 2, {T_DIR | T_IND, T_REG}, 10, 1, 0},
{14, "lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 50,
	1, 1},
{15, "lfork", 1, {T_DIR}, 1000, 0, 1},
{16, "aff", 1, {T_REG}, 2, 1, 0},
{0, 0, 0, {0}, 0, 0, 0}
};

#endif