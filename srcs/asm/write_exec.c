/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:05:22 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 15:05:52 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	write_exec_code(t_asm *assem, int fd)
{
	t_state 		*state;
	unsigned char	code;

	state = assem->state;
	while(state)
	{
		code = ((unsigned char)state->state_code + 1);
		write(fd, &code, 1);
		write(fd, &state->result, 1);
		state = state->next;
	}
}
