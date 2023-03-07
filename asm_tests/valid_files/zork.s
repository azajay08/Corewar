.name "zork"
.comment "I'M ALIIIIVE"


live:
l2:		sti r1, %:live, %1
		and r1, %65536, r1

live:	live %45876767676896686896786786876876876876
		zjmp %:live
