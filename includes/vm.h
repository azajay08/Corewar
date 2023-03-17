/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:11:23 by ajones            #+#    #+#             */
/*   Updated: 2023/03/17 14:44:55 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include "op_table.h"
# include <stdbool.h>

// DEBUG: Set to 1 if you wish to see debug messages
# define DEBUG 0

typedef struct s_player
{
	unsigned int	id;
	int				last_live;
	int				live_count;
	unsigned int	magic;
	unsigned char	name[PROG_NAME_LENGTH + 1];
	unsigned char	comment[COMMENT_LENGTH + 1];
	unsigned char	*exec;
	unsigned int	exec_size;
	unsigned char	file[MEM_SIZE];
	struct s_player	*next;
}	t_player;

typedef struct s_args
{
	int		type;
	int		value;
}	t_args;

typedef struct s_carriage
{
	t_player			*player;
	int					id;
	int					carry;
	t_args				args[3];
	int					registers[REG_NUMBER];
	int					pos;
	int					cycles_until_exec;
	int					bytes_to_next;
	int					last_live_cycle;
	int					result_code;
	uint32_t			op_code;
	bool				dead;
	struct s_carriage	*next;
}	t_carriage;

typedef struct s_corewar
{
	int				cycles;
	int				cycles_to_die;
	int				cycles_since_check;
	int				lives_this_period;
	int				checks;
	int				carry;
}	t_corewar;

typedef struct s_vm
{
	uint32_t	player_count;
	t_carriage	*carriages;
	t_player	*player[MAX_PLAYERS];
	int			latest_live;
	uint8_t		arena[MEM_SIZE];
	uint8_t		print_octets;
	size_t		carriage_count;
	size_t		total_carriagees;
	int			cycle;
	int			cycles_to_die;
	int			checks;
	int			dump;
}	t_vm;

// Initialisation:
void		init_vm(t_vm *vm);
void		init_players(t_vm *vm, unsigned int player_count);
void		init_arena(t_vm *vm);

// Parsing:
void		parse_flags(t_vm *vm, int argc, char **argv);
void		set_player_order(t_player *player, char *input_id);
int			set_dump_cycle(t_vm *vm, char *input, char *value);
void		parse(int argc, char **argv, t_vm *vm);
int			read_cor(char **av, int i, t_player *player);
int			parse_file(\
			unsigned char *player_data, unsigned char *data, int len);
int			parse_size(uint32_t *exec_size, unsigned char *data, uint32_t i);
int			get_n_byte(unsigned int n, unsigned char *data, unsigned int idx);
void		get_player_count(int ac, char **av, uint32_t *player_count);

// Game process:
void		introduce_players(t_vm *vm);
void		print_arena(t_vm *vm);
void		print_carriages(t_vm *vm);
void		game_process(t_vm *vm);
int			byte_to_int(uint8_t *arena, int position);
void		cycle_check(t_vm *vm, t_corewar *corewar);
void		apply_statement(t_vm *vm, t_carriage *carriage);
void		execute_statement(t_vm *vm, t_carriage *carriage, t_corewar *cw);

// Carriages:
void		set_carriages(t_vm *vm);
t_carriage	*initialise_carriage(t_player *player, uint32_t pos);
void		new_carriage(t_carriage **carriagees, t_carriage *new_carriage);

// Game utilities
void		reset_args(t_carriage *carriage);
void		move_to_next_statement(t_carriage *carriage);
void		count_bytes_to_skip(t_carriage *carriage);
int			arg_byte_count(t_carriage *carriage, int type);
int			reg_check(t_carriage *carriage, t_vm *vm);
int			byte_to_int(uint8_t *arena, int position);
int			arg_byte_count(t_carriage *carriage, int type);

// Exit program:
void		exit_vm(char *error_message);

//Statements:

// Statement utilities:
void		sort_state_8(\
			int state, t_carriage *carriage, t_corewar *cw, t_vm *vm);
void		sort_state_16(\
			int state, t_carriage *carriage, t_corewar *cw, t_vm *vm);
void		get_arg_values(t_carriage *carriage, t_vm *vm, t_corewar *cw);
int			check_args_validity(t_carriage *carriage);
int			check_reg_validity(t_carriage *carriage, t_vm *vm, int offset);
int8_t		get_bit_pair(int byte, u_int8_t nth_pair);
int8_t		check_args(t_carriage *carriage);
u_int16_t	get_pos(u_int16_t pos);

#endif
