.name "123 1234"
.comment "abcd efgh     "

l1:


l1:sti r1,%:live,%0

 zjmp	%:l1

l2:	
	zjmp	%:l1
live:	live	%1
	zjmp	%:l1

 live	%1

