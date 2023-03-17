/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:56 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 16:34:56 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* -
*/
void	ft_zjmp(t_carriage *carriage)
{
	if (carriage->carry == 1)
		carriage->pos = mod_calculator(carriage->args[0].value % IDX_MOD);
}
