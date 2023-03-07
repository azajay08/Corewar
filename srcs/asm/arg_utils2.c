/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:02:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 15:03:02 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	arg_code(char *arg)
{
	if (!arg[0])
		return (0);
	if (arg[0] == DIRECT_CHAR)
		return (DIR_CODE);
	if (arg[0] == REG_CHAR)
		return (REG_CODE);
	return (IND_CODE);
}

char	bit_shift(unsigned char byte, int type, int shift)
{
	if (type == DIR_CODE || type == IND_CODE)
		byte |= 1UL << shift;
	shift--;
	if (type == REG_CODE || type == IND_CODE)
		byte |= 1UL << shift;
	return (byte);
}

char	get_arg_result(t_asm *assem, char **args)
{
	unsigned char	byte;
	int				type;
	int				i;
	int				shift;

	i = 0;
	byte = 0;
	type = 0;
	shift = 7;
	while (args[i])
	{
		type = arg_code(args[i]);
		if (!type)
			error_exit1(ARG_TYPE, assem);
		byte = bit_shift(byte, type, shift);
		shift -= 2;
		i++;
	}
	return (byte);
}
