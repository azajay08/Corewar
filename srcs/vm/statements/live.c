/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:47:37 by sam               #+#    #+#             */
/*   Updated: 2023/03/21 15:05:15 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// void	test_function(t_vm *vm, int value)
// {
// 	int i;
// 	t_vm *temp;

// 	temp = vm;

// 	i = 0;
// 	while (i < (int)temp->player_count)
// 	{
// 		if ((int)temp->player[i]->id == value)
// 			break ;
// 		i++;
// 	}
// 	if (i == (int)temp->player_count)
// 		i--;
// 	temp->player[i]->last_live = vm->cycle;
// }

/*
* - Live counts that carriage, which performs the live statement, is alive.
*/
void	ft_live(t_carriage *carriage, t_corewar *corewar, t_vm *vm)
{
	int	value;

	carriage->last_live_cycle = corewar->cycles;
	corewar->lives_this_period++;
	value = carriage->args[0].value;
	value *= -1;
	if (value > 0 && value <= (int)vm->player_count)
		vm->latest_live = value;
}
