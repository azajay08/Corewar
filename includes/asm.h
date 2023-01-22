/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajones <ajones@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:12:53 by ajones            #+#    #+#             */
/*   Updated: 2023/01/22 18:10:47 by ajones           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define USAGE "Usage: ./asm [filename.s]\n"
# define EXT_S "Invalid file! Input file must have [.s] extension\n"

# include "../libft/includes/libft.h"

typedef struct	s_asm
{
	char		*name;
}				t_asm;

int	main(int argc, char **argv);

#endif