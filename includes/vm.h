/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:11:23 by ajones            #+#    #+#             */
/*   Updated: 2023/03/13 18:10:41 by swilliam         ###   ########.fr       */
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

typedef struct	s_player
{
	unsigned int		id;
	int					last_live;
	int					live_count;
	unsigned int		magic;
	unsigned char		name[PROG_NAME_LENGTH + 1];
	unsigned char		comment[COMMENT_LENGTH + 1];
	unsigned char		*exec;
	unsigned int		exec_size;
	unsigned char		file[MEM_SIZE];
	struct s_player		*next;
}				t_player;

typedef struct	s_process
{
	t_player			*player;
	int					id;
	int					carry;
	uint8_t				args[3];
	int					registers[REG_NUMBER];
	int					pos;
	int					cycles_until_exec;
	int					last_live_cycle;
	uint32_t			op_code;
	bool				executed;
	struct s_process	*next;
}				t_process;

typedef struct	s_corewar
{
	int					cycles_total;
	int					cycles;
	int					cycles_to_die;
	int					lives_this_round;
	int					checks;
	int					carry;
}				t_corewar;

typedef struct	s_vm
{
	uint32_t		player_count;
	t_process		*processes;
	t_player		*player[MAX_PLAYERS];
	int				latest_live;
	uint8_t			arena[MEM_SIZE];
	uint8_t			print_octets;
	size_t			process_count;
	size_t			total_processes;
	int				cycle;
	int				cycles_to_die;
	int				checks;
	int				cycle_dump;
}				t_vm;

// Initialisation:
void		init_vm(t_vm *vm);
void		init_players(t_vm *vm, unsigned int player_count);
void		init_arena(t_vm *vm);

// Parsing:
<<<<<<< HEAD
void		parse_flags(t_vm *vm, int argc, char **argv);
void		parse(int argc, char **argv, t_vm *vm);
int			read_cor(char **av, int i, t_player *player);
int			parse_file(unsigned char *player_data, unsigned char *data, int len);
int			parse_size(uint32_t *exec_size, unsigned char *data, uint32_t i);
int			get_n_byte(unsigned int n, unsigned char *data, unsigned int idx);
void		get_player_count(int ac, char **av, uint32_t *player_count);
=======
void	parse_flags(t_vm *vm, int argc, char **argv);
void	set_player_order(t_player *player, char *input_id);
int		set_dump_cycle(t_vm *vm, char *input, char *value);
void	parse(int argc, char **argv, t_vm *vm);
int		read_cor(char **av, int i, t_player *player);
int		parse_file(unsigned char *player_data, unsigned char *data, int len);
int		parse_size(uint32_t *exec_size, unsigned char *data, uint32_t i);
int		get_n_byte(unsigned int n, unsigned char *data, unsigned int idx);
void	get_player_count(int ac, char **av, uint32_t *player_count);
>>>>>>> c87453a1228d6937ed4512a76e6dee3b6724c2b0

// Game process:
void		introduce_players(t_vm *vm);
void		print_arena(t_vm *vm);
void		print_processes(t_vm *vm);
void		game_process(t_vm *vm);
int			byte_to_int(uint8_t *arena, int position);

// Processes:
void		set_processes(t_vm *vm);
t_process	*initialise_process(t_player *player, uint32_t pos);
void		new_process(t_process **processes, t_process *new_process);

// Exit program:
void		exit_vm(char *error_message);

//statement stuff:
int8_t		get_bit_pair(u_int8_t byte, u_int8_t nth_pair);
int8_t		check_args(t_process *process);
u_int16_t	get_pos(u_int16_t pos);

#endif
