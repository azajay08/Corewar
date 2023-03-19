/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:56 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 03:32:09 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_zjmp(t_carriage *carriage)
{
	if (carriage->carry == 1)
		carriage->pos = mod_calculator(carriage->pos \
			+ carriage->args[0].value % IDX_MOD);
}
