# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 00:15:54 by ajones            #+#    #+#              #
#    Updated: 2023/01/20 03:10:56 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_ASM := asm
NAME_CW := corewar

#FLAGS:
FLAGS := -Wall -Werror -Wextra

#INCLUDES:
COR_INC := -I./includes/
LIB_INC := -I./libft/includes
LIBFT := libft/libft.a
LIB := -L./libft/includes -lft

#SOURCES:
ASM_SRCS := 

ASM_DIR := $(addprefix srcs/asm/, $(ASM_SRCS))

ASM_OBJ := $(ASM_SRCS:%.c=%.o)


CW_SRCS := 

CW_DIR := $(addprefix srcs/vm/, $(CW_SRCS))

CW_OBJ := $(CW_SRCS:%.c=%.o)

#OBJECTS:

O_PATH := ./obj/
O_DIR := $(addprefix $(O_PATH), $(O_FILES))

#COLORS:
GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME)

$(NAME_ASM): $(LIBFT) $(O_PATH) $(O_DIR)
	@echo ${CYAN}"Making $(@) executable...${RESET}"
	@gcc $(FLAGS) $(COR_INC) $(LIB_INC) $(O_DIR) $(LIB) -o $(NAME)
	@echo ${GREEN}"Executable successfully made${RESET}"

$(LIBFT):
	@make -C libft

$(O_PATH):
	@mkdir -p $(O_PATH)

$(O_PATH)%.o: $(SRCS_PATH)%.c
	@gcc -c $(FLAGS) $(LEM_INC) $(LIB_INC)  -o $@ $<

$(NAME_CW): $(LIBFT) $(O_PATH) $(O_DIR)
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
