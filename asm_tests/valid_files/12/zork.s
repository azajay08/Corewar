.name "zork"
.comment "I'M ALIIIIVE"

l2:		sti r1, %:live, %1
		and r1, %0, r16

live:	live %12098345729385728934572938547298345729083457209835472098345729834570
		zjmp %:live
