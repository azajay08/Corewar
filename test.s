# .comment

.name "I am the champion,
I have no name"
.comment"This is the comment"

zjmp: lld r1,%:live,%0
lld r1,%:live,%0
		lld r1	, %:live ,   %0
		lldr1, %:live, %0       

live:sti r1,%:live,%0
		sti r1,%:live,%0;hello
		sti r1,%:live,%0#hello
		sti r1,%:live,%0;   hello
		sti r1,%:live,%0#   hello
		sti r1,%:live,%0         ;hello
		sti r1,%:live,%0         #hello
		sti r1,%:live,%0     ;	 hello
		sti r1,%:live,%0     #	 hello
sti: zjmp	%:zjmp
 
2_label:


3_label:
