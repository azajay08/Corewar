/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egaliber <egaliber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:56 by sam               #+#    #+#             */
/*   Updated: 2023/03/19 16:21:55 by egaliber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Zjmp sets where the carriage should move to perform the next statement.
* - Its is affected by carry. If carry value is 0 nothing happens.
*/
void	ft_zjmp(t_carriage *carriage)
{
	if (carriage->carry == 1)
		carriage->pos = mod_calculator(carriage->pos \
			+ carriage->args[0].value % IDX_MOD);
}
