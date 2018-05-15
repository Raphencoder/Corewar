.comment            "a"
.name "ie     1er mais pas dernier"

start:
	st r1, 6
	live %0
	ld %10, r2
	ld %0, r3
	fork %:top
	bottom:
	st r3, 104
	st r3, 107
	st r3, 110
	st r3, 113
	st r3, 116
	st r3, 119
	st r3, 122
	st r1, 6
	live %26
	zjmp %:bottom
	top:
	st r3, -88 
	st r3, -101
	st r3, -114
	st r3, -127
	st r3, -140
	st r3, -153
	st r3, -166
	st r1, 6
	live %26
	zjmp %:top
