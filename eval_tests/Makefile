# ---------------------------------------------------------------------------- #
# 						A testing Makefile for Corewar.						   #
# ---------------------------------------------------------------------------- #

# General:
# - all: Creates the assembler and virtual machine in the root directory.
# - clean: Removes all object files.
# - fclean: Removes all objects, libraries, executables and logs.
# - re: Uses fclean to fully clean the project, and recreates the asm and VM.
# - norm: Runs the norminette command on all project files.
WAR_DIR = ..

# ---------------------------------------------------------------------------- #

# Assembler:
# - asmtest: Compares the output of valid files between 42 and our assembler.
# - asmspeed: Compares the assembly speed between 42 and our assembler.
# - asmerror: Compares the output of error files between 42 and our assembler.
# - asminv: Compares the output of invalid files with 42 and our assembler.
OUR_ASM = $(WAR_DIR)/asm
SCH_ASM = ./42/asm
ASM_ERR = ./asm_test_files/error_files
ASM_INV = ./asm_test_files/invalid_files
ASM_SPD = ./asm_test_files/speed_files
ASM_VLD = ./asm_test_files/valid_files

# ---------------------------------------------------------------------------- #

# Virtual machine:
# - 42: Runs the 42 corewar with the assigned champs and flags.
# - test: Runs corewar with the assigned champs and flags.
# - compare: Compares 42 and our VMs to find the cycle an error occurs.
# - vmleaks: Runs champs against each other, testing for leaks.
# - mayhem: Runs all champs against each other.
# - mychamp: Runs our own champion against others.
LOG_DIR = ./logs
OUR_VM = $(WAR_DIR)/corewar
SCH_VM = ./42/corewar42
FLAGS = -dump 2147483647 -b
# Our champion:
OUR_CHAMP = Conman
OUR_CHAMP_S = ./$(OUR_CHAMP).s
OUR_CHAMP_C = ./$(OUR_CHAMP).cor
# Champions to test:
CHAMP_D = ./champs/compiled
CHAMP_1 = $(CHAMP_D)/all_instructions.cor
CHAMP_2 = $(CHAMP_D)/THUNDER.cor
CHAMP_3 = $(CHAMP_D)/car.cor
CHAMP_4 = $(CHAMP_D)/NoIdea.cor

# ---------------------------------------------------------------------------- #
# General:																	   #
# ---------------------------------------------------------------------------- #
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

# ---------------------------------------------------------------------------- #
# Assembler:																   #
# ---------------------------------------------------------------------------- #
asmtest:	all
			@bash asm_test.sh -a $(ASM_VLD)

asmerror:	all
			@bash asm_test.sh -a $(ASM_ERR)

asminv:		all
			@bash asm_test.sh -a $(ASM_INV)

asmspeed:	all
			@bash asm_test.sh -a $(ASM_SPD)

# ---------------------------------------------------------------------------- #
# Virtual machine:															   #
# ---------------------------------------------------------------------------- #
42:
			@$(SCH_VM) $(FLAGS) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3)

test:		all
			@$(OUR_VM) $(FLAGS) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3)

compare:	all
			@mkdir -p $(LOG_DIR)
			@sh vm_compare.sh

mayhem:		all
			@mkdir -p $(LOG_DIR)
			@python3 vm_mayhem.py

vmleaks:	all
			@mkdir -p $(LOG_DIR)
			@python3 vm_leaks.py

mychamp1:	all
			../asm $(OUR_CHAMP_S)
			@../corewar -b $(OUR_CHAMP_C) $(CHAMP_1) $(CHAMP_2) $(CHAMP_3) -d 0

mychamp2:	all
			../asm $(OUR_CHAMP_S)
			@python3 vm_our_champ.py

# ---------------------------------------------------------------------------- #
# Phony:																	   #
# ---------------------------------------------------------------------------- #
.PHONY: all clean fclean re norm asmtest asmspeed asmerror 42 test compare \
		mayhem vmerrors vmleaks mychamp