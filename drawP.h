drawPacman	proc 
			push ax bx cx dx si

			push topLeftX
			pop currentX

			push topLeftY
			pop currentY

			mov si, 0

			cmp movTo, 'w'
			jz	a00
			jmp a0
	a00:
	blc1:	cmp pStkU_O[si], 255
			jz Y11
			jmp E11
	Y11:	cmp	si, [arrU_O]
			jnz a4
			jmp endPacDraw
	a4:
			inc si
			inc currentY
			mov bx, [topLeftX]
			mov currentX, bx
	E11:	cmp pStkU_O[si], 0
			jz zr11
			mov al, 0				;draw black
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkU_O[si]
	dra11:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra11
	zr11:	inc si
	clr1:	
			cmp pStkU_O[si], 255
			jz Y21
			jmp E21
	Y21:	cmp	si, [arrU_O]
			jnz a5
			jmp endPacDraw
	a5:
			inc currentY
			inc si
			mov bx, [topLeftX]
			mov currentX, bx
			jmp E11
	E21:	cmp pStkU_O[si], 0
			jz zr21
			mov al, 14			;draw color
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkU_O[si]
	dra21:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra21
	zr21:	inc si
			jmp blc1
	a0:
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			cmp movTo, 'a'
			jz	a11
			jmp a1
	a11:

	blc2:	cmp pStkL_O[si], 255
			jz Y12
			jmp E12
	Y12:	cmp	si, [arrL_O]
			jnz a6
			jmp endPacDraw
	a6:
			inc si
			inc currentY
			mov bx, [topLeftX]
			mov currentX, bx
	E12:	cmp pStkL_O[si], 0
			jz zr12
			mov al, 0				;draw black
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkL_O[si]
	dra12:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra12
	zr12:	inc si
	clr2:	
			cmp pStkL_O[si], 255
			jz Y22
			jmp E22
	Y22:	cmp	si, [arrL_O]
			jnz a7
			jmp endPacDraw
	a7:
			inc currentY
			inc si
			mov bx, [topLeftX]
			mov currentX, bx
			jmp E12
	E22:	cmp pStkL_O[si], 0
			jz zr22
			mov al, 14			;draw color
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkL_O[si]
	dra22:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra22
	zr22:	inc si
			jmp blc2
	a1:
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			cmp movTo, 's'
			jz	a22
			jmp a2
	a22:

	blc3:	cmp pStkD_O[si], 255
			jz Y13
			jmp E13
	Y13:	cmp	si, [arrD_O]
			jnz a8
			jmp endPacDraw
	a8:
			inc si
			inc currentY
			mov bx, [topLeftX]
			mov currentX, bx
	E13:	cmp pStkD_O[si], 0
			jz zr13
			mov al, 0				;draw black
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkD_O[si]
	dra13:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra13
	zr13:	inc si
	clr3:	
			cmp pStkD_O[si], 255
			jz Y23
			jmp E23
	Y23:	cmp	si, [arrD_O]
			jnz a9
			jmp endPacDraw
	a9:
			inc currentY
			inc si
			mov bx, [topLeftX]
			mov currentX, bx
			jmp E13
	E23:	cmp pStkD_O[si], 0
			jz zr23
			mov al, 14			;draw color
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkD_O[si]
	dra23:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra23
	zr23:	inc si
			jmp blc3
	a2:	
	;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			cmp movTo, 'd'
			jz	a33
			jmp a3
	a33:

	blc4:	cmp pStkR_O[si], 255
			jz Y14
			jmp E14
	Y14:	cmp	si, [arrR_O]
			jnz a10
			jmp endPacDraw
	a10:
			inc si
			inc currentY
			mov bx, [topLeftX]
			mov currentX, bx
	E14:	cmp pStkR_O[si], 0
			jz zr14
			mov al, 0				;draw black
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkR_O[si]
	dra14:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra14
	zr14:	inc si
	clr4:	
			cmp pStkR_O[si], 255
			jz Y24
			jmp E24
	Y24:	cmp	si, [arrR_O]
			jnz a12
			jmp endPacDraw
	a12:
			inc currentY
			inc si
			mov bx, [topLeftX]
			mov currentX, bx
			jmp E14
	E24:	cmp pStkR_O[si], 0
			jz zr24
			mov al, 14			;draw color
			mov bh, 0
			mov ah, 0ch
			mov dh, pStkR_O[si]
	dra24:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra24
	zr24:	inc si
			jmp blc4
	a3:
			

	endPacDraw:
			pop si dx cx bx ax
			ret
	drawPacman endp