OUR="our.txt"
THEIR="42.txt"

./corewar -dump $1 turtle.cor toto.cor zork.cor > $OUR

./eval_tests/42/corewar42 -d $1 ./eval_tests/champs/compiled/op_add.cor ./eval_tests/champs/compiled/op_aff.cor ./eval_tests/champs/compiled/op_fork.cor > $THEIR

diff $OUR $THEIR