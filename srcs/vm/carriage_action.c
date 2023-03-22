/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_action.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:57:40 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 14:44:56 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Updates the carriage to contain the code at the given arena position.
* - Converts the op_code at the position into an integer. If this integer
*   correlates to one of the registry statements, the carriage grabs the cycles
*   until its execution from the op_table and stores it.
*/
void	apply_statement(t_vm *vm, t_carriage *carriage)
{
	int	byte_as_int;

	byte_as_int = vm->arena[carriage->pos];
	carriage->op_code = byte_as_int;
	if (byte_as_int >= 1 && byte_as_int <= 16)
		carriage->cycles_until_exec = g_op_tab[byte_as_int - 1].cycles;
}

/*
* - Executes the statement correlating to the op code at the arena position.
* - We first make sure that statement is between 1 and 16. If it is, its saved,
*   otherwise we skip a byte.
* - Then we save the binary code (result code).
* - We then start validating and checking arg values for that statement.
* - After that we count how many bytes we need to move to the next statement.
* - Finally we move the carriage to the next statement.
*/
void	execute_statement(t_vm *vm, t_carriage *carriage, t_corewar *cw)
{
	int	position;

	position = vm->arena[carriage->pos];
	if (position >= 1 && position <= 16)
	{
		carriage->result_code = (vm->arena[(carriage->pos + 1) % MEM_SIZE]);
		if (check_args_validity(carriage))
		{
			if (reg_check(carriage, vm))
			{
				get_arg_values(carriage, vm, cw);
				if (vm->b_flag)
					ft_printf("%sExecuting %s%s\n", \
					YEL, g_op_tab[carriage->op_code - 1].state_name, RESET);
			}
		}
		count_bytes_to_skip(carriage);
		move_to_next_statement(carriage);
	}
	else
		carriage->pos = (carriage->pos + 1) % MEM_SIZE;
}
