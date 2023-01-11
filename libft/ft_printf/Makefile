# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 10:56:50 by ajones            #+#    #+#              #
#    Updated: 2022/09/16 17:13:04 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := ft_printf.c format_c.c format_s.c format_di.c format_o.c format_x.c \
format_percent.c init_flags.c itoa_dioux.c format_u.c di_helpers.c sorter.c \
format_p.c format_f.c f_helpers.c data_conv.c di_zero_helpers.c

O_PRINTF := $(SRCS:.c=.o)

NAME := libftprintf.a
FLAGS := -c -Wall -Werror -Wextra
INCL := -I ./includes
LIB_A := ../libft.a
SRC_PATH := srcs/
P_SRCS := $(addprefix $(SRC_PATH), $(SRCS))

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) $(INCL) $(P_SRCS)
	@cp $(LIB_A) $(NAME)
	@ar rc $(NAME) $(O_PRINTF)

clean:
	@rm -f $(O_PRINTF)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all
