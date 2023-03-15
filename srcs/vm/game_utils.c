/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 11:09:20 by sam               #+#    #+#             */
/*   Updated: 2023/03/15 17:02:22 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** byte_to_int:
** - Takes the value of the given position in the arena, casting it as an int
**   so that it can be used to find which statement to execute.
*/
int	byte_to_int(uint8_t *arena, int position)
{
	return ((int)arena[position]);
}
