OUR="our.txt"
THEIR="42.txt"

./corewar -dump $1 youforkmytralala.cor weird_load.cor wave.cor > $OUR

./eval_tests/42/corewar42 -d $1 youforkmytralala.cor weird_load.cor wave.cor > $THEIR

diff $OUR $THEIR