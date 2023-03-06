# .comment

.name "I am the champion,
I have no name"
.comment"This is the comment"

zjmp: lld r2,%:live
lld 3,%:live, g
		lld r1	, %:live
		lld r1, %:live     

live:sti r1,%:live,%0
		sti r1,%:live,%0;hello
st:	sti r1,%:live,%0#hello
		sti r1,%:live,%0;   hello
		sti r1,%:live,%0#   hello
		sti r1,%:live,%0         ;hello
		sti r1,%:live,%0         #hello
		sti r1,%:live,%0     ;	 hello
		sti r1,%:live,%0     #	 hello
sti: zjmp	%:zjmp
 
2_label:


3_label:
