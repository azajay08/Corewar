/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:46 by sam               #+#    #+#             */
/*   Updated: 2023/03/22 17:18:45 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - St writes a value from the registry that was passed as the first parameter.
* - If the first argument is registry its written from registry to registry.
* - If the first argument is indirect its written to a certain position in the
* - arena.
*/
void	ft_st(t_carriage *carriage, t_vm *vm)
{
	int	result;

	if (carriage->args[1].type == T_REG)
		carriage->registers[carriage->args[1].value - 1] \
		= carriage->registers[carriage->args[0].value];
	else if (carriage->args[1].type == T_IND)
	{
		result = carriage->pos + carriage->args[1].value % IDX_MOD;
		write_n_byte(vm, result, 3, \
				carriage->registers[carriage->args[0].value - 1]);
	}
}
