/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:46 by sam               #+#    #+#             */
/*   Updated: 2023/03/18 16:02:27 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_st(t_carriage *carriage, t_vm *vm)
{
	if (carriage->args[1].type == T_REG)
		carriage->registers[carriage->args[1].value - 1] = carriage->args[0].value;
	else if (carriage->args[1].type == T_IND)
		write_n_byte(vm, carriage->args[1].value, 3, carriage->registers[carriage->args[0].value - 1]);
}
