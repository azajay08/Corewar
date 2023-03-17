/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:30 by sam               #+#    #+#             */
/*   Updated: 2023/03/16 16:25:26 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** handle_ld:
** -
*/
void	ft_ld(t_carriage *carriage)
{
	if (carriage->args[0].type == T_IND)
		carriage->registers[carriage->args[1].value - 1] = carriage->args[0].value % IDX_MOD;
	else
		carriage->registers[carriage->args[1].value - 1] = carriage->args[0].value;
	if (carriage->args[0].value == 0)
		carriage->carry = 1;
	else
		carriage->carry = 0;
}
