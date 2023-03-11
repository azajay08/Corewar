/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:02:19 by ajones            #+#    #+#             */
/*   Updated: 2023/03/11 17:39:01 by ajones           ###   ########.fr       */
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

/*
	bit_shift uses the bitwise operator to shift 1s along the binary string
	depending on the argument type
*/

char	bit_shift(unsigned char byte, int type, int shift)
{
	if (type == DIR_CODE || type == IND_CODE)
		byte |= 1UL << shift;
	shift--;
	if (type == REG_CODE || type == IND_CODE)
		byte |= 1UL << shift;
	return (byte);
}

/*
	get_arg_result returns the results from the argument types as binary.
	The argument types in the case, can only be one of 3 values, 1,2 and 3. Or
	in binary 01, 10 and 11. To complete the binary string, the unused
	argument space is filled with 00. For example a complete string that
	contains IND as arg 1, DIR as arg 2, and REG as arg 3. The binary would
	look like this '11100100' 11 = IND, 10 = DIR, 01 = REG, 00 to fill.
	11100100 = 228 in decimal, which = E4 in hexadecimal. That would be
	the result.
*/

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
			error_exit1(ARG_TYPE, LINE_REF, assem);
		byte = bit_shift(byte, type, shift);
		shift -= 2;
		i++;
	}
	return (byte);
}
