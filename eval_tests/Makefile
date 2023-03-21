# A testing Makefile for Corewar.
WAR_DIR = ..
OUR_WAR = $(WAR_DIR)/corewar
SCH_WAR = ./42/corewar42
FLAGS = -b -d 25

CHAMP_D = ./champs/compiled
CHAMP_1 = $(CHAMP_D)/zork.cor
#CHAMP_2 = $(CHAMP_D)/ex.cor
#CHAMP_3 = $(CHAMP_D)/slider2.cor

COMPARE = ./compare_multiple_players.sh
LOG_DIR = ./logs

all:
			@make all -C $(WAR_DIR)

clean:
			@make clean -C $(WAR_DIR)
			@rm -rf $(LOG_DIR)

fclean:		clean
			@make fclean -C $(WAR_DIR)

re:			fclean all

norm:
			@norminette -R CheckForbiddenSourceHeader ../includes
			@norminette -R CheckForbiddenSourceHeader ../srcs

42:
			@$(SCH_WAR) $(FLAGS) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3)

test:		all
			@$(OUR_WAR) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3) $(FLAGS)

pytest:		all
			@mkdir -p $(LOG_DIR)
			@python3 test.py

mayhem:		all
			@mkdir -p $(LOG_DIR)
			@python3 test_mayhem.py

errors:		all
			@mkdir -p $(LOG_DIR)
			@python3 test_errors.py

leaks:		all
			@mkdir -p $(LOG_DIR)
			@python3 test_leaks.py

compare:	all
			@mkdir -p $(LOG_DIR)
			@sh $(COMPARE)

.PHONY: all clean fclean re norm test compare 42 pytest