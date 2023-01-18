# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 00:15:54 by ajones            #+#    #+#              #
#    Updated: 2023/01/18 15:08:57 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 

#FLAGS:
FLAGS := -Wall -Werror -Wextra

#INCLUDES:
COR_INC := -I./includes/
LIB_INC := -I./libft/includes
LIBFT := libft/libft.a
LIB := -L./libft/includes -lft

#SOURCES:
SRCS := 

SRCS_PATH := ./srcs/
SRCS_DIR := $(addprefix $(SRCS_PATH), $(SRCS))

#OBJECTS:
O_FILES := $(SRCS:%.c=%.o)
O_PATH := ./obj/
O_DIR := $(addprefix $(O_PATH), $(O_FILES))

#COLORS:
GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME)

$(NAME): $(LIBFT) $(O_PATH) $(O_DIR)
	@echo ${CYAN}"Making $(@) executable...${RESET}"
	@gcc $(FLAGS) $(COR_INC) $(LIB_INC) $(O_DIR) $(LIB) -o $(NAME)
	@echo ${GREEN}"Executable successfully made${RESET}"

$(LIBFT):
	@make -C libft

$(O_PATH):
	@mkdir -p $(O_PATH)

$(O_PATH)%.o: $(SRCS_PATH)%.c
	@gcc -c $(FLAGS) $(LEM_INC) $(LIB_INC)  -o $@ $<

clean:
	@echo ${RED}"Removing obj directory...${RESET}"
	@rm -rf $(O_PATH)
	@make -C libft clean

fclean: clean
	@echo ${RED}"Removing $(NAME)...${RESET}"
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

.PHONY := all re clean fclean make
