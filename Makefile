# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: swilliam <swilliam@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 00:15:54 by ajones            #+#    #+#              #
#    Updated: 2023/03/09 17:26:40 by swilliam         ###   ########.fr        #
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
ASM_SRCS := main.c init.c errors.c free.c read_file.c verify.c parse_header.c \
parse_labels.c parse_utils.c

ASM_PATH := srcs/asm/
ASM_DIR := $(addprefix $(ASM_PATH), $(ASM_SRCS))
ASM_OBJ := $(ASM_SRCS:%.c=%.o)
ASM_O_PATH := srcs/asm/obj/
ASM_O_DIR := $(addprefix $(ASM_O_PATH), $(ASM_OBJ))

# VIRTUAL MACHINE

CW_SRCS := \
main.c init.c exit_program.c \
parse_players_1.c parse_players_2.c parse_utils.c \
game_process.c arena.c processes.c \
debug_printing.c

CW_PATH := srcs/vm/
CW_DIR := $(addprefix $(CW_PATH), $(CW_SRCS))
CW_OBJ := $(CW_SRCS:%.c=%.o)
CW_O_PATH := srcs/vm/obj/
CW_O_DIR := $(addprefix $(CW_O_PATH), $(CW_OBJ))


#COLORS:
GREEN := '\033[1;3;32m'
CYAN := '\033[2;3;36m'
RED := '\033[2;3;31m'
RESET := \033[0m

all: $(NAME_ASM) $(NAME_CW)

$(LIBFT):
	@make -C libft

$(NAME_ASM): $(LIBFT) $(ASM_O_PATH) $(ASM_O_DIR)
	@echo ${CYAN}"Making $(@) executable...${RESET}"
	@gcc $(FLAGS) $(COR_INC) $(LIB_INC) $(ASM_O_DIR) $(LIBFT) -o $(NAME_ASM)
	@echo ${GREEN}"Executable successfully made${RESET}"

$(ASM_O_PATH):
	@mkdir -p $(ASM_O_PATH)

$(ASM_O_PATH)%.o: $(ASM_PATH)%.c
	@gcc -c $(FLAGS) $(COR_INC) $(LIB_INC) -o $@ $<

$(NAME_CW): $(LIBFT) $(CW_O_PATH) $(CW_O_DIR)
	@echo ${CYAN}"Making $(@) executable...${RESET}"
	@gcc $(FLAGS) $(COR_INC) $(LIB_INC) $(CW_O_DIR) $(LIBFT) -o $(NAME_CW)
	@echo ${GREEN}"Executable successfully made${RESET}"

$(CW_O_PATH):
	@mkdir -p $(CW_O_PATH)

$(CW_O_PATH)%.o: $(CW_PATH)%.c
	@gcc -c $(FLAGS) $(COR_INC) $(LIB_INC) -o $@ $<

clean:
	@echo ${RED}"Removing obj directory & files...${RESET}"
	@rm -rf $(ASM_O_PATH)
	@rm -rf $(CW_O_PATH)
	@make -C libft clean

fclean: clean
	@echo ${RED}"Removing executables...${RESET}"
	@rm -f $(NAME_ASM)
	@rm -f $(NAME_CW)
	@make -C libft fclean

re: fclean all

.PHONY := all re clean fclean make asm corewar
