/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:06 by ajones            #+#    #+#             */
/*   Updated: 2023/03/08 16:48:52 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	verify_label(t_asm *assem, char *arg)
{
	t_label	*label;

	label = assem->label;
	while (label)
	{
		if (ft_strequ(label->label_name, arg))
			return ;
		label = label->next;
	}
	error_exit1(INV_LBL, assem);
}

void	check_reg_arg(t_asm *assem, char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			error_exit1(ARG_ERR, assem);
		i++;
	}
	if (i == 1)
		error_exit1(ARG_ERR, assem);
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
		error_exit1(ARG_ERR, assem);
	}
	if (arg[i])
	{
		if (arg[i] == '-')
			i++;
		while (arg[i])
		{
			if (!ft_isdigit(arg[i]))
				error_exit1(ARG_ERR, assem);
			i++;
		}
		return ;
	}
	error_exit1(ARG_ERR, assem);
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
		error_exit1(ARG_ERR, assem);
	}
	if (arg[i])
	{
		if (arg[i] == '-')
			i++;
		while (arg[i])
		{
			if (!ft_isdigit(arg[i]))
				error_exit1(ARG_ERR, assem);
			i++;
		}
		return ;
	}
	error_exit1(ARG_ERR, assem);
}
