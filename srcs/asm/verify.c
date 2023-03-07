/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:58:16 by ajones            #+#    #+#             */
/*   Updated: 2023/03/07 18:29:12 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	verify_arguments(t_asm *assem, t_state *state)
{
	int	i;

	i = 0;
	while (i < state->arg_count)
	{
		if (arg_value(state->args[i]) == T_REG)
			check_reg_arg(assem, state->args[i]);
		else if (arg_value(state->args[i]) == T_DIR)
			check_dir_arg(assem, state->args[i]);
		else if (arg_value(state->args[i]) == T_IND)
			check_ind_arg(assem, state->args[i]);
		else
			error_exit1(ARG_ERR, assem);
		i++;
	}
}

void	verify_filename(char *filename)
{
	if (!ft_strequ(ft_strrchr(filename, '.'), ".s"))
	{
		ft_putstr(EXT_S);
		error_exit(USAGE);
	}
}

void	verify_name_com(t_asm *assem, t_line *line)
{
	if (!assem->champ_name || !assem->champ_com || !line)
		error_exit1(INV_FILE, assem);
	if (ft_strlen(assem->champ_name) > PROG_NAME_LENGTH)
		error_exit1(LONG_NAME, assem);
	if (ft_strlen(assem->champ_com) > COMMENT_LENGTH)
		error_exit1(LONG_COM, assem);
}
