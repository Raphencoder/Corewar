.comment""
.name "qqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqq"

start:
	st r1, 6
	live %0
	ld %10, r2
	ld %0, r3
	fork %:top
	bottom:
	st r3, 104
	live %26
	zjmp %:bottom
	top:
	live %26
