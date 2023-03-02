/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:11:23 by ajones            #+#    #+#             */
/*   Updated: 2023/03/02 14:28:31 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"

typedef struct	s_process
{
	int					id;
	int					carry;
	int					registers[REG_NUMBER];
	int					cool_down;
	struct s_process	*next;
}				t_process;

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

typedef struct	s_vm
{
	t_process		*process;
	t_player		*latest_live;
	uint8_t			arena[MEM_SIZE];
	size_t			process_amount;
	size_t			total_processes;
	int				cycle;
	int				cycle_to_die;
	int				checks;
	unsigned int	player_count;
}				t_vm;

// Initialisation:
void	init_vm(t_vm *vm);
void	init_players(t_player *players, unsigned int player_count);

// Parsing:
void	parse(int argc, char **argv, t_player *players, t_vm *vm);
int		read_cor(char **av, int i, t_player *player);
int		parse_file(unsigned char *player_data, unsigned char *data, int len);
int		parse_size(uint32_t *exec_size, unsigned char *data, uint32_t i);
int		get_n_byte(unsigned int n, unsigned char *data, unsigned int idx);
void	get_player_count(int ac, char **av, uint32_t *player_count);

// Exit program:
void	exit_vm(char *error_message);

#endif
