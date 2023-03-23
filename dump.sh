OUR="our.txt"
THEIR="42.txt"

./corewar -dump $1 turtle.cor toto.cor zork.cor > $OUR

./eval_tests/42/corewar42 -d $1 turtle.cor toto.cor zork.cor > $THEIR

# ./corewar -dump $1 eval_tests/champs/compiled/Asombra.cor eval_tests/champs/compiled/Backward_fixed.cor eval_tests/champs/compiled/Bazou.cor > $OUR

#  ./eval_tests/42/corewar42 -d $1 eval_tests/champs/compiled/Asombra.cor eval_tests/champs/compiled/Backward_fixed.cor eval_tests/champs/compiled/Bazou.cor > $THEIR 
diff $OUR $THEIR