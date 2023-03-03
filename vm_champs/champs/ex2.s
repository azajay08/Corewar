.name "zork"
.comment	"just a basic living prog"
		
l1:
l2:	sti	r1,%:live,%0
	and	r1,%0,r1
	zjmp	%:live
live:	

	live	%1
	zjmp	%:live
	zjmp	%:live
	and	r1,%0,r1
	and	r1,%0,r1
	zjmp	%:live
