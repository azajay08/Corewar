.name "123 1234"
.comment "abcd efgh     "

l1:
and	r6, %0, r6
ld %3, r6

l1:sti r1,:l2,%0

 zjmp	%:l1

l2:	
	zjmp%:l1
live:	live	%1
	zjmp	%:l1

 live%1

