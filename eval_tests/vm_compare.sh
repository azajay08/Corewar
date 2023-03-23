FILE_DIR=( ./champs/strugglers/*)
FT_OUTPUT="./logs/corewar42.txt"
OUR_OUTPUT="./logs/corewar.txt"
OUR_WAR="../corewar"
SCHOOL_WAR="./42/corewar42"

PASS=0
TEST_OK=0
NOT_PASS=0
i=0
FILE_ID=0
FILE_NUM=0
INCREMENT=5000
RED='\033[31m'
GREEN='\033[32m'
YELLOW='\033[33m'
MAGENTA='\033[35m'
NOCOLOR='\033[0m'
run_games() {
	$OUR_WAR -dump $1 ${FILE[@]} | tail -n 64 > $OUR_OUTPUT
	$SCHOOL_WAR -d $1 ${FILE[@]} | tail -n 64 > $FT_OUTPUT
	DIFF=$(diff $OUR_OUTPUT $FT_OUTPUT)
}

print_chosen_files_menu()
{
	x=0
	echo "${GREEN}Currently chosen files: ${NOCOLOR}"

	if ((ARGS_AMOUNT == 0)); then
		echo "None"
		((x += 1))
	fi

	while ((x < ARGS_AMOUNT))
	do
		echo "${FILE[$x]}, id = ${FILE_ID_ARR[$x]} "
		((x += 1))
	done

	while ((x < 4)); do
		echo ""
		((x += 1))
	done
	echo ""
}

print_chosen_files_after_game() {
	x=0
	echo "Files, used in this run:"

	while ((x < ARGS_AMOUNT))
	do
		echo "\t${FILE[$x]}, id = ${FILE_ID_ARR[$x]} "
		((x += 1))
	done
}

overwrite() {
	echo "\033[11A";
}

choose_file() {
	if ((FILE_ID < 0)); then
		((FILE_ID = (${#FILE_DIR[@]} - 1)))
	fi

	if ((FILE_ID > (${#FILE_DIR[@]} - 1))); then
		((FILE_ID = 0))
	fi

	print_chosen_files_menu
	echo "\r\033[KChoose player $FILE_NUM"
	echo "\r\033[Kfile_id = $FILE_ID"
	if (($FILE_ID >= 0)); then
		echo "\r\033[K${FILE_DIR[FILE_ID]}"
	else
		echo "\r\033[KFile_id has to be >= 0"
	fi

	read -n1 -s -r -p $'\n' key

	case "$key" in
	$'[' )
		((FILE_ID -= 1))
		FILE_ID_ARR[FILE_NUM]=$FILE_ID
		overwrite
		choose_file
		;;
	$']' )
		((FILE_ID += 1))
		FILE_ID_ARR[FILE_NUM]=$FILE_ID
		overwrite
		choose_file
		;;
	$'\e' )
		((FILE_ID = -1))
		exit 1
		;;
	$yes )
		FILE[FILE_NUM]=${FILE_DIR[FILE_ID]}
		((FILE_ID = 0))
		((FILE_NUM += 1))
		((ARGS_AMOUNT += 1))
		if ((FILE_NUM > 3))
		then
			echo "Max amount of players has been chosen"
			sleep "1"
			return
		fi
		overwrite
		choose_file
		;;
	$'r' )
		if ((FILE_NUM < 1))
		then
			((FILE_ID = -1))
			overwrite
			choose_file
		else
			return
		fi
		;;
	* )
		overwrite
		choose_file
		;;
	esac
}

print_commands() {
	echo "Commands, used to run last games:"

	echo "\t$OUR_WAR -dump $1 ${FILE[@]} | tail -n 64 > $OUR_OUTPUT"
	echo "\t$SCHOOL_WAR -d $1 ${FILE[@]} | tail -n 64 > $FT_OUTPUT"
}

print_controls() {
	echo "Controls:"
	echo "\tPress [ to choose previous file"
	echo "\tPress ] to choose next file"
	echo "\tESC to exit"
	echo "\tPress enter to choose file\n"
	echo "\tPress 'r' to confirm you've chosen all players\n"
	ARGS_AMOUNT=0
	choose_file
}

print_pass() {
	run_games "$NOT_PASS"
	echo "${YELLOW}Diff one cycle before game end:${NOCOLOR} (should be empty)"
	echo $(diff $OUR_OUTPUT $FT_OUTPUT)
	echo "${YELLOW}Provided vm output after the game:${NOCOLOR}"
	cat $FT_OUTPUT
	echo ""
	echo "${YELLOW}Our vm output after the game:${NOCOLOR}"
	cat $OUR_OUTPUT
	echo ""
	echo "${GREEN}Last game cycle is $PASS${NOCOLOR}"
	echo ""
}

print_fail() {
	run_games "$PASS"
	echo "${YELLOW}Diff one cycle before occurance${NOCOLOR} (should be empty)"
	echo $(diff $OUR_OUTPUT $FT_OUTPUT)

	run_games "$NOT_PASS"
	echo "${YELLOW}Diff at time of occurance${NOCOLOR}"
	echo $(diff -d -y $OUR_OUTPUT $FT_OUTPUT)
}

ARGS_AMOUNT=$#
if ((ARGS_AMOUNT >= 1)); then
	for j in "$@"; do
		FILE[$FILE_NUM]=${FILE_DIR[j]}
		FILE_ID_ARR[$FILE_NUM]=$j
		((FILE_NUM += 1))
	done
else
	print_controls
fi

print_chosen_files_menu 0
while true; do
	echo "Testing with -dump $i"
	run_games "$i"
	if [[ $DIFF != "" ]]
	then
		echo "${RED}diff with -dump $i isn't empty${NOCOLOR}\n"
		((NOT_PASS = i))
		((i= PASS + (NOT_PASS - PASS) / 2))
	else
		((TEST_OK = 0))
		GREP=$(tail -1 $OUR_OUTPUT | grep "has won")
		if [[ $GREP != "" ]]
		then
			((TEST_OK = 1))
			((NOT_PASS = i))
			echo "${GREEN}Test passed with -dump $i${NOCOLOR}"
			echo "${MAGENTA}Looking for the last cycle before game end${NOCOLOR}\n"
		else
			echo "${GREEN}diff with -dump $i empty${NOCOLOR}\n"
		((PASS = i))
		fi

		if  ((NOT_PASS != 0))
		then
			((i= PASS + (NOT_PASS - PASS) / 2))
		else
			((i=i+INCREMENT))
		fi
	fi

	if (((NOT_PASS - PASS) == 1)) || ((i == 0))
	then
		run_games "$NOT_PASS"
		GREP=$(tail -1 $OUR_OUTPUT | grep "has won")
		if [[ $GREP != "" ]]
		then
			((TEST_OK = 1))
		fi
		if ((i != 0)); then
			if ((TEST_OK == 0))
			then
				print_fail
			else
				print_pass
				break
			fi
		else
			echo "${RED}Something went wrong${NOCOLOR}"
			echo diff = $DIFF
		fi
		echo "${RED}diff occured at -dump $NOT_PASS${NOCOLOR}\n"
		break
	fi
done

echo "Gerenal info:\n"
print_commands $i
print_chosen_files_after_game
if ((TEST_OK))
then
	echo ${GREEN}Test passed${NOCOLOR}
else
	echo "${RED}Test didn't pass ${NOCOLOR}"
