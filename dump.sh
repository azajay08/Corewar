OUR="our.txt"
THEIR="42.txt"

./corewar -dump $1 turtle.cor toto.cor zork.cor > $OUR

./eval_tests/42/corewar42 -d $1 turtle.cor toto.cor zork.cor > $THEIR

diff $OUR $THEIR