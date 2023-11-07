	.name "Abel"
	.comment "L'amer noir."

	sti r1, %:hi, %r1

hi:	live %234
	ld %0, r3
	zjmp %:hi
