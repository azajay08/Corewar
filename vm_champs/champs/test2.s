.name "123 1234"
.comment "abcd efgh     "

l2:
l3:
l4:
	sti	r1,%:live,%0
	and	r1,%0,r17
	zjmp	%:live
	zjmp	%:live
	zjmp	%:live
	and	r1,%0,r1
live:	live	%1
