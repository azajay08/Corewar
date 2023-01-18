# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 10:56:43 by ajones            #+#    #+#              #
#    Updated: 2023/01/18 15:01:49 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC_FILES = ft_isalpha.c ft_isdigit.c ft_isprint.c ft_tolower.c ft_toupper.c \
ft_isascii.c ft_isalnum.c ft_putchar.c ft_putstr.c ft_strlen.c ft_strcmp.c \
ft_strncmp.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_putendl.c ft_strcat.c \
ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_putnbr.c ft_strstr.c \
ft_strnstr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_bzero.c ft_strclr.c ft_memset.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_atoi.c ft_memalloc.c ft_memdel.c ft_strnew.c \
ft_strdel.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
ft_lstadd_toend.c ft_lstcount.c ft_lstfree.c ft_lstlast.c ft_abs.c ft_intlen.c \
ft_isspace.c ft_2d_free.c ft_strjoin_free1.c ft_strjoin_free2.c ft_power.c \
ft_power_double.c ft_round.c ft_is_neg.c ft_strjoin_line.c get_next_line.c 

SRC_PATH := ./srcs/
SRC_DIR := $(addprefix $(SRC_PATH), $(SRC_FILES))

O_FILES := $(SRC_FILES:%.c=%.o)
O_PATH := ./obj/
O_DIR := $(addprefix $(O_PATH), $(O_FILES))

FLAGS = -Wall -Wextra -Werror

GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m
P_LIB := ft_printf/libftprintf.a
LIB_INC := -I./includes/

all: $(NAME)

$(NAME): $(O_PATH) $(O_DIR)
	@echo ${CYAN}"Compiling libft...${RESET}"
	@ar rc $(NAME) $(O_DIR)
	@make -C ft_printf
	@cp $(P_LIB) $(NAME)
	@echo ${GREEN}"Libft compiled successfully${RESET}"

$(O_PATH):
	@mkdir -p $(O_PATH)

$(O_PATH)%.o: $(SRC_PATH)%.c
	@gcc $(FLAGS) $(LIB_INC) -c $< -o $@

	
clean:
	@echo ${RED}"Removing libft .o files...${RESET}"
	@rm -rf $(O_PATH)
	@make -C ft_printf clean
	
fclean: clean
	@echo ${RED}"Removing libft.a...${RESET}"
	@rm -f $(NAME)
	@make -C ft_printf fclean

re: fclean all

.PHONY := all re clean fclean make