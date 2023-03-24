/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:05:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/24 13:04:06 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
	These 3 functions write to the output file with the corresponding argument
	byte values.
*/
void	write_reg(int bytes, int fd)
{
	write(fd, &((unsigned char *)&bytes)[0], 1);
}

void	write_ind(int bytes, int fd)
{
	write(fd, &((unsigned char *)&bytes)[1], 1);
	write(fd, &((unsigned char *)&bytes)[0], 1);
}

void	write_dir(t_state *state, int bytes, int fd)
{
	if (g_op_tab[state->state_code].size_t_dir == 4)
	{
		write(fd, &((unsigned char *)&bytes)[3], 1);
		write(fd, &((unsigned char *)&bytes)[2], 1);
	}
	write(fd, &((unsigned char *)&bytes)[1], 1);
	write(fd, &((unsigned char *)&bytes)[0], 1);
}

/*
	This goes through all the statements and writes all the data and argument
	results from the statements.
*/
void	write_exec_code(t_asm *assem, int fd)
{
	int		i;
	int		code;
	t_state	*state;

	i = 0;
	state = assem->state;
	while (state)
	{
		code = state->state_code + 1;
		write(fd, &((unsigned char *)&code)[0], 1);
		if (g_op_tab[state->state_code].arg_type_code)
			write(fd, &state->result, 1);
		i = 0;
		while (i < state->arg_count)
		{
			if (arg_value(state->args[i]) == T_DIR)
				write_dir(state, state->arg_val[i], fd);
			else if (arg_value(state->args[i]) == T_IND)
				write_ind(state->arg_val[i], fd);
			else
				write_reg(state->arg_val[i], fd);
			i++;
		}
		state = state->next;
	}
}
