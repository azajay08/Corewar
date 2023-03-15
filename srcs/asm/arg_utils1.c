/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:25:34 by ajones            #+#    #+#             */
/*   Updated: 2023/03/15 01:49:18 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
	Byte_length checks the length of bytes needed for specific arguments to 
	eventually get a total amount of bytes for the entire statement
*/

int	byte_length(t_asm *assem, int type)
{
	if (type == T_REG)
		return (1);
	else if (type == T_IND)
		return (2);
	else if (type == T_DIR)
		return (g_op_tab[assem->state_code].size_t_dir);
	else
		return (0);
}

int	arg_value(char *arg)
{
	if (!arg[0])
		return (0);
	if (arg[0] == DIRECT_CHAR)
		return (T_DIR);
	if (arg[0] == REG_CHAR)
		return (T_REG);
	return (T_IND);
}

/*
	Get_byte_count goes through the argument of the statement to check how 
	many bytes need to be allocated for that specific combination of arguments.
	Using the bitwsie operator '&', we can check that the argument is a valid
	one for that specific statement.
*/

int	get_byte_count(t_asm *assem, char **args)
{
	int	byte_count;
	int	type;
	int	i;

	i = 0;
	byte_count = 0;
	type = 0;
	while (args[i])
	{
		type = arg_value(args[i]);
		if (!type)
			error_exit1(ARG_TYPE, LINE_REF, assem);
		if (!(g_op_tab[assem->state_code].arg_type[i] & type))
			error_exit1(ARG_TYPE, LINE_REF, assem);
		type = byte_length(assem, type);
		if (!type)
			error_exit1(ARG_TYPE, LINE_REF, assem);
		byte_count += type;
		i++;
	}
	if (g_op_tab[assem->state_code].arg_type_code == 1)
		byte_count++;
	return (byte_count + 1);
}
