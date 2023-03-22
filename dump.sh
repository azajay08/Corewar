OUR="our.txt"
THEIR="42.txt"

./corewar -dump $1 turtle.cor toto.cor zork.cor > $OUR

./eval_tests/42/corewar42 -d $1 ./eval_tests/champs/compiled/_honeybadger.cor ./eval_tests/champs/compiled/corelol.cor ./eval_tests/champs/compiled/Car.cor > $THEIR

diff $OUR $THEIR