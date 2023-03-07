/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:44:06 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 17:03:14 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	check_reg_arg(t_asm *assem, char *arg)
{
	int	i;

	i = 1;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]));
			error_exit1(ARG_ERR, assem);
		i++;
	}
	if (i == 1)
		error_exit1(ARG_ERR, assem);
	if (ft_atoi(ft_strchr(arg, 'r') + 1) > 16
		|| ft_atoi(ft_strchr(arg, 'r') + 1) < 1)
		error_exit1(ARG_ERR, assem);
}

void	check_dir_arg(t_asm *assem, char *arg)
{
	int	i;

	i = 1;
	if (arg[i] == LABEL_CHAR)
		verify_label()
}

void	check_ind_arg(t_asm *assem, char *arg)
{
	
}