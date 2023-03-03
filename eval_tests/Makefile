# A testing Makefile for Corewar.
WAR_DIR = ../
OUR_WAR = ../corewar
SCH_WAR = ./vm_champs/corewar42

CHAMP_D = ./vm_champs/champs
CHAMP_1 = $(CHAMP_D)/Gagnant.cor
CHAMP_2 = $(CHAMP_D)/ex.cor
CHAMP_3 = $(CHAMP_D)/42.cor

COMPARE = ./compare_multiple_players.sh

all:
			@make all -C $(WAR_DIR)

clean:
			@make clean -C $(WAR_DIR)

fclean:		clean
			@make fclean -C $(WAR_DIR)

re:			fclean all

norm:
			@norminette ../libft
			@norminette ../srcs
			@norminette ../includes

test:		all
			$(OUR_WAR) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3)

compare:	all
			sh $(COMPARE)
.PHONY: all clean fclean re norm test compare