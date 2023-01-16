# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajones <ajones@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 00:15:54 by ajones            #+#    #+#              #
#    Updated: 2023/01/05 20:33:24 by ajones           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := lem-in

#FLAGS:
FLAGS := -Wall -Werror -Wextra

#INCLUDES:
LEM_INC := -I./includes/
LIB_INC := -I./libft/
LIBFT := libft/libft.a
LIB := -L./libft/ -lft

#SOURCES:
SRCS := l_main.c l_init.c l_errors.c l_read_input.c l_free.c l_read_ants.c \
		l_read_rooms.c l_read_links.c l_bfs.c l_solver.c l_helpers.c \
		l_room_array.c l_bfs_helpers.c l_calculations.c l_free_all.c \
		l_vertex_disjoint.c l_printing.c l_print_extra.c l_ants.c \
		l_bfs_vertex.c l_delete_edge.c l_line_helpers.c
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
	@gcc $(FLAGS) $(LEM_INC) $(LIB_INC) $(O_DIR) $(LIB) -o $(NAME)
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
