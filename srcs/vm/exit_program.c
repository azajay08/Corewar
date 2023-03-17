/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sam <sam@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:13:42 by sam               #+#    #+#             */
/*   Updated: 2023/03/17 14:27:26 by sam              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
* - Used to exit the program at any time with a custom error message.
*/
void	exit_vm(char *error_message)
{
	ft_printf("ERROR: %s\n", error_message);
	exit(EXIT_FAILURE);
}
