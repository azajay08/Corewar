/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:06 by ajones            #+#    #+#             */
/*   Updated: 2023/03/12 17:52:30 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_reg_arg(t_asm *assem, char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit1(ARG_ERR, LINE_REF, assem);
		i++;
	}
	if (i == 1)
		error_exit1(ARG_ERR, LINE_REF, assem);
	if (ft_atoi(&arg[1]) > 99)
		error_exit1(ARG_ERR, LINE_REF, assem);
}

void	check_dir_arg(t_asm *assem, char *arg)
{
	int	i;

	i = 1;
	if (arg[i] == LABEL_CHAR)
	{
		if (arg[i + 1])
		{
			verify_label(assem, ft_strchr(arg, LABEL_CHAR) + 1);
			return ;
		}
		error_exit1(ARG_ERR, LINE_REF, assem);
	}
	if (arg[i])
	{
		if (arg[i] == '-')
			i++;
		while (arg[i])
		{
			if (!ft_isdigit(arg[i]))
				error_exit1(ARG_ERR, LINE_REF, assem);
			i++;
		}
		return ;
	}
	error_exit1(ARG_ERR, LINE_REF, assem);
}

void	check_ind_arg(t_asm *assem, char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == LABEL_CHAR)
	{
		if (arg[i + 1])
		{
			verify_label(assem, ft_strchr(arg, LABEL_CHAR) + 1);
			return ;
		}
		error_exit1(ARG_ERR, LINE_REF, assem);
	}
	if (arg[i])
	{
		if (arg[i] == '-')
			i++;
		while (arg[i])
		{
			if (!ft_isdigit(arg[i]))
				error_exit1(ARG_ERR, LINE_REF, assem);
			i++;
		}
		return ;
	}
	error_exit1(ARG_ERR, LINE_REF, assem);
}
