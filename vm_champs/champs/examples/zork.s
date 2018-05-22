.name "zork"
.comment "I'M ALIIIIVE"

live:	live %1
		zjmp %:live
		live    %4902343
		st      r2, -24
cc_live:
		live %0
