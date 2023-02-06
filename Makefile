# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 00:15:54 by ajones            #+#    #+#              #
#    Updated: 2023/02/06 14:54:12 by ajones           ###   ########.fr        #
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

# ASSEMBLER
ASM_SRCS := main.c init.c errors.c

ASM_PATH := srcs/asm/

ASM_DIR := $(addprefix $(ASM_PATH), $(ASM_SRCS))

ASM_OBJ := $(ASM_SRCS:%.c=%.o)

ASM_O_PATH := srcs/asm/obj/

ASM_O_DIR := $(addprefix $(ASM_O_PATH), $(ASM_OBJ))

# VIRTUAL MACHINE

VM_SRCS := main.c

VM_PATH := srcs/vm/

VM_DIR := $(addprefix $(VM_PATH), $(VM_SRCS))

VM_OBJ := $(VM_SRCS:%.c=%.o)

VM_O_PATH := srcs/vm/obj/

VM_O_DIR := $(addprefix $(VM_O_PATH), $(VM_OBJ))

O_PATH := ./obj/
O_DIR := $(addprefix $(O_PATH), $(O_FILES))

#COLORS:
GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME)

$(NAME_ASM): $(LIBFT) $(ASM_O_PATH) $(ASM_O_DIR)
	@echo ${CYAN}"Making $(@) executable...${RESET}"
	@gcc $(FLAGS) $(COR_INC) $(LIB_INC) $(ASM_O_DIR) $(LIB) -o $(NAME_ASM)
	@echo ${GREEN}"Executable successfully made${RESET}"

$(LIBFT):
	@make -C libft

$(ASM_O_PATH):
	@mkdir -p $(ASM_O_PATH)

$(ASM_O_PATH)%.o: $(ASM_PATH)%.c
	@gcc -c $(FLAGS) $(COR_INC) $(LIB_INC)  -o $@ $<

$(NAME_CW): $(VM_O_PATH) $(VM_O_DIR)
	@echo ${CYAN}"Making $(@) executable...${RESET}"
	@gcc $(FLAGS) $(COR_INC) $(LIB_INC) $(O_DIR) $(LIB) -o $(NAME)
	@echo ${GREEN}"Executable successfully made${RESET}"


$(VM_O_PATH):
	@mkdir -p $(VM_O_PATH)

$(VM_O_PATH)%.o: $(VM_PATH)%.c
	@gcc -c $(FLAGS) $(COR_INC) $(LIB_INC)  -o $@ $<

clean:
	@echo ${RED}"Removing obj directory...${RESET}"
	@rm -rf $(ASM_O_PATH)
	@rm -rf $(VMM_O_PATH)
	@make -C libft clean

fclean: clean
	@echo ${RED}"Removing $(NAME)...${RESET}"
	@rm -f $(ASM_NAME)
	@rm -f $(CW_NAME)
	@make -C libft fclean

re: fclean all

.PHONY := all re clean fclean make
