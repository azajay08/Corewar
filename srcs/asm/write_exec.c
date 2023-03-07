/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:05:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 19:28:20 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_exec_code(t_asm *assem, int fd)
{
	t_state 		*state;
	unsigned char	code;
	int	i;
	int	num;

	i = 0;
	state = assem->state;
	while(state)
	{
		code = ((unsigned char)state->state_code + 1);
		write(fd, &code, 1);
		if (g_op_tab[state->state_code].arg_type_code)
			write(fd, &state->result, 1);
		i = 0;
		while (i < state->arg_count)
		{
			num = state->arg_val[i];
			if (arg_value(state->args[i]) == T_DIR)
			{
				if (g_op_tab[state->state_code].size_t_dir == 4)
				{
					write(fd, &((unsigned char *)&num)[3], 1);
					write(fd, &((unsigned char *)&num)[2], 1);
				}
			}
			if (arg_value(state->args[i]) == T_DIR || arg_value(state->args[i]) == T_IND)
				write(fd, &((unsigned char *)&num)[1], 1);
			write(fd, &((unsigned char *)&num)[0], 1);
			i++;
		}
		state = state->next;
	}
}
