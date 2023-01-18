# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 10:56:50 by ajones            #+#    #+#              #
#    Updated: 2023/01/18 14:58:19 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_FILES := ft_printf.c format_c.c format_s.c format_di.c format_o.c format_x.c \
format_percent.c init_flags.c itoa_dioux.c format_u.c di_helpers.c sorter.c \
format_p.c format_f.c f_helpers.c data_conv.c di_zero_helpers.c

O_PRINTF := $(SRC_FILES:.c=.o)

O_FILES := $(SRC_FILES:%.c=%.o)
O_PATH := ./obj/
O_DIR := $(addprefix $(O_PATH), $(O_FILES))

NAME := libftprintf.a
FLAGS := -c -Wall -Werror -Wextra
INCL := -I ./includes
LIB_A := ../libft.a
SRC_PATH := srcs/
P_SRCS := $(addprefix $(SRC_PATH), $(SRC_FILES))

all: $(NAME)

$(NAME): $(O_PATH) $(O_DIR) $(LIB_A)
	@cp $(LIB_A) $(NAME)
	@ar rc $(NAME) $(O_DIR)

$(O_PATH):
	@mkdir -p $(O_PATH)

$(O_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) $(INCL) -c $< -o $@

clean:
	@rm -rf $(O_PATH)

fclean: clean
	@rm -f $(NAME)
	
re: fclean all

.PHONY := all re clean fclean make