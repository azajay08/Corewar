/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:11:23 by ajones            #+#    #+#             */
/*   Updated: 2023/01/20 17:46:48 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "../libft/includes/libft.h"
# include "op.h"

typedef struct s_processor	t_processor;
typedef struct s_vm			t_vm;
typedef struct s_player		t_player;

struct	s_processor
{
	int			id;
	int			registers[REG_NUMBER];
	int			cool_down;
	t_processor	*next;
};

struct s_player
{
	unsigned int		id;
	unsigned int		magic;
	unsigned char		name[PROG_NAME_LENGTH + 1];
	unsigned int		exec_size;
	unsigned char		comment[COMMENT_LENGTH + 1];
	unsigned char		*exec;
	unsigned char		file[MEM_SIZE];
};

struct	s_vm
{
	t_processor		*processors;
	t_player		*latest_live;
	int				cycle;
	int				cycle_to_die;
	int				checks;
	unsigned int	player_count;
};

// registers?? x16

int		main(int argc, char **argv);
void	parse(int argc, char **argv, t_player *players, t_vm *vm);
void	init_vm(t_vm *vm);
int		get_n_byte(unsigned int n, unsigned char *data, unsigned int idx);
void	init_players(t_player *players, unsigned int player_count);

#endif
