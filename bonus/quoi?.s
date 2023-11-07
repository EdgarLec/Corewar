.name    "Quoi ?"
.comment "Feur"

	sti	r1, %:live, %1
	fork	%:live
	ld %81, r1
    ld %117, r2
    ld %111, r3
    ld %105, r4
    ld %32, r5
    ld %70, r6
    ld %101, r7
    ld %117, r8
    ld %114, r9
    ld %33, r10
    ld %33, r11
    ld %10, r12
    zjmp %:rickroll

live:	live	%2
	ld	%0, r4
	zjmp	%:live
rickroll:   aff r1
    aff r2
    aff r3
    aff r4
    aff r5
    aff r6
    aff r7
    aff r8
    aff r9
    aff r10
    aff r11
    aff r12
	zjmp	%:rickroll
