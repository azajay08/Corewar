# A testing Makefile for Corewar.
WAR_DIR = ../
OUR_WAR = $(WAR_DIR)/corewar
SCH_WAR = ./42/corewar42

CHAMP_D = ./champs/compiled
CHAMP_1 = $(CHAMP_D)/Gagnant.cor
CHAMP_2 = $(CHAMP_D)/ex.cor
CHAMP_3 = $(CHAMP_D)/42.cor

COMPARE = ./compare_multiple_players.sh
LOG_DIR = ./logs

all:
			@make all -C $(WAR_DIR)

clean:
			@make clean -C $(WAR_DIR)
			rm -rf $(LOG_DIR)

fclean:		clean
			@make fclean -C $(WAR_DIR)

re:			fclean all

norm:
			@norminette ../libft
			@norminette ../srcs
			@norminette ../includes

42:
			$(SCH_WAR) -n $(CHAMP_1) $(CHAMP_2) $(CHAMP_3)

test:		all
			$(OUR_WAR) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3)

compare:	all
			mkdir -p $(LOG_DIR)
			sh $(COMPARE)

.PHONY: all clean fclean re norm test compare 42