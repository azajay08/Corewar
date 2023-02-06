/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:53 by ajones            #+#    #+#             */
/*   Updated: 2023/02/06 15:07:37 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define USAGE "Usage: ./asm [filename.s]\n"
# define EXT_S "Invalid file! Input file must have [.s] extension\n"
# define ASSEM "ERROR! Memory allocation of t_asm failed!\n"

# include "../libft/includes/libft.h"

typedef struct	s_asm
{
	char		*filename;
}				t_asm;

int		main(int argc, char **argv);

/*
	Initialising
*/

void	init_asm(t_asm *assem, char *file_input);

/*
	Errors
*/

void	error_exit(char *exit_str);

#endif