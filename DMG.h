drawGhost	proc
			pop bx cx dx ax
			push bx
			
			mov currentX, cx		;cx
			mov currentY, dx		;dx
			
			push topLeftX
			push topLeftY

			mov topLeftX, cx 
			mov topLeftY, dx
			
			push ax

			mov si, 0

	blc10:	cmp gStk[si], 255
			jz Y110
			jmp E110
	Y110:	cmp	si, [arrG]
			jnz a40
			jmp endGDraw
	a40:
			inc si
			inc currentY
			mov bx, [topLeftX]
			mov currentX, bx
	E110:	cmp gStk[si], 0
			jz zr110
			mov al, 0				;draw black
			mov bh, 0
			mov ah, 0ch
			mov dh, gStk[si]
	dra110:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra110
	zr110:	inc si
	;clr1:	
			cmp gStk[si], 255
			jz Y210
			jmp E210
	Y210:	cmp	si, [arrG]
			jnz a50
			jmp endGDraw
	a50:
			inc currentY
			inc si
			mov bx, [topLeftX]
			mov currentX, bx
			jmp E110
	E210:	cmp gStk[si], 0
			jz zr210
			pop ax				;draw color
			push ax
			mov bh, 0
			mov ah, 0ch
			mov dh, gStk[si]
	dra210:	push dx
			mov dx, [currentY]
			mov cx, [currentX]
			int 10h
			inc currentX
			pop dx
			dec dh
			jnz dra210
	zr210:	inc si
			jmp blc10
			
	endGDraw:
			pop ax
			pop topLeftY
			pop topLeftX
			
			ret
	drawGhost	endp
	
	moveGhost	proc
			pop bx cx dx ax			;ax = direction
			push bx
			
			mov currentX, cx		;cx
			mov currentY, dx		;dx
			
			mov dpg, 60000
			
			push ax
			
			push 0
	
			;w
			
			mov ah, 0dh
			mov bh, 0

			mov dx, [currentY]			;row
			dec dx
			mov cx,	[currentX]			;col
			dec cx
			int 10h
			cmp al, 1
			jz c410

			dec dx						;row
			int 10h
			cmp al, 1
			jz c410

			add cx, 6					;col
			int 10h
			cmp al, 1
			jz c410
			
			inc dx						;row
			int 10h
			cmp al, 1
			jz c410
			
			add cx, 6					;col
			int 10h
			cmp al, 1
			jz c410
			
			dec dx						;row
			int 10h
			cmp al, 1
			jz c410

			mov cx, [topLeftX]
			sub cx, [currentX]
			jnc dg0
			mov cx, [currentX]
			sub cx, [topLeftX]
			
	dg0:	mov dx, [topLeftY]
			add dx, 5
			sub dx, [currentY]
			jnc xg0
			mov dx, [currentY]
			sub dx, 5
			sub dx, [topLeftY]
	xg0:	
			add cx, dx
			cmp dpg, cx
			jc c410
			
			pop ax bx
			push bx ax
			cmp bx, 's'
			jnz d01
			jmp c410
			
	d01:	mov dpg, cx
			pop cx
			push 'w'
			
			
			
			
			
	c410:	;a

			mov ah, 0dh
			mov bh, 0
	
			mov dx, [currentY]			;row
			dec dx
			mov cx,	[currentX]			;col
			dec cx
			int 10h
			cmp al, 1
			jnz ui03
			jmp c50

	ui03:	dec cx						;col
			int 10h
			cmp al, 1
			jnz ui04
			jmp c50

	ui04:	add dx, 6					;row
			int 10h
			cmp al, 1
			jnz ui30
			jmp c50

	ui30:	inc cx						;col
			int 10h
			cmp al, 1
			jnz ui31
			jmp c50
			
	ui31:	add dx, 6					;row
			int 10h
			cmp al, 1
			jz c50
			
			dec cx						;col
			int 10h
			cmp al, 1
			jz c50
			
			mov cx, [currentX]			;col
			mov dx, [currentY]			;row
			cmp dx, 97					
			jz ui20
			jmp ui21
			
	ui20:	cmp cx, 248
			jz c50
			
	ui21:	cmp dx, 98				
			jz ui22
			jmp ui23
			
	ui22:	cmp cx, 59
			jz c50
	ui23:

			mov cx, [topLeftX]
			add cx, 5
			sub cx, [currentX]
			jnc dg1
			mov cx, [currentX]
			sub cx, 5
			sub cx, [topLeftX]
			
	dg1:	mov dx, [topLeftY]
			sub dx, [currentY]
			jnc xg1
			mov dx, [currentY]
			sub dx, [topLeftY]
	xg1:				
			add cx, dx
			cmp dpg, cx
			jc c50
			
			pop ax bx
			push bx ax
			cmp bx, 'd'
			jnz d02
			jmp c50
			
	d02:	mov dpg, cx
			pop cx
			push 'a'
			
	c50:	;s	
	
			mov ah, 0dh
			mov bh, 0
	
			mov dx, [currentY]			;row
			add dx, 11
			mov cx,	[currentX]			;col
			dec cx
			int 10h
			cmp al, 1
			jz c60

			inc dx						;row
			int 10h
			cmp al, 1
			jz c60

			add cx, 6					;col
			int 10h
			cmp al, 1
			jz c60

			dec dx						;row
			int 10h
			cmp al, 1
			jz c60
			
			add cx, 6					;col
			int 10h
			cmp al, 1
			jz c60
			
			inc dx						;row
			int 10h
			cmp al, 1
			jz c60

			mov cx, [topLeftX]
			sub cx, [currentX]
			jnc dg2
			mov cx, [currentX]
			sub cx, [topLeftX]
			
	dg2:	mov dx, [topLeftY]
			add dx, 5
			sub dx, [currentY]
			jnc xg2
			mov dx, [currentY]
			add dx, 5
			sub dx, [topLeftY]
	xg2:				
			add cx, dx
			cmp dpg, cx
			jc c60
			
			pop ax bx
			push bx ax
			cmp bx, 'w'
			jnz d03
			jmp c60
			
	d03:	mov dpg, cx
			pop cx
			push 's'
			
	c60:	;d	
	
			mov ah, 0dh
			mov bh, 0
	
			mov dx, [currentY]			;row
			dec dx
			mov cx,	[currentX]			;col
			add cx, 11
			int 10h
			cmp al, 1
			jnz ui01
			jmp c70

	ui01:	inc cx						;col
			int 10h
			cmp al, 1
			jnz ui02
			jmp c70

	ui02:	add dx, 6					;row
			int 10h
			cmp al, 1
			jnz ui05
			jmp c70

	ui05:	dec cx						;row
			int 10h
			cmp al, 1
			jnz ui06
			jmp c70
			
	ui06:	add dx, 6					;row
			int 10h
			cmp al, 1
			jz c70
			
			inc cx						;col
			int 10h
			cmp al, 1
			jz c70
			
			mov cx, [currentX]			;col
			mov dx, [currentY]			;row
			cmp dx, 97					
			jz ui10
			jmp ui11
			
	ui10:	cmp cx, 248
			jz c70
			
	ui11:	cmp dx, 98				
			jz ui12
			jmp ui13
			
	ui12:	cmp cx, 59
			jz c70
	ui13:
	
			mov cx, [topLeftX]
			sub cx, 5
			sub cx, [currentX]
			jnc dg3
			mov cx, [currentX]
			add cx, 5
			sub cx, [topLeftX]
			
	dg3:	mov dx, [topLeftY]
			sub dx, [currentY]
			jnc xg3
			mov dx, [currentY]
			sub dx, [topLeftY]
	xg3:				
			add cx, dx
			cmp dpg, cx
			jc c70
			
			pop ax bx
			push bx ax
			cmp bx, 'a'
			jnz d04
			jmp c70
			
	d04:	mov dpg, cx
			pop cx
			push 'd'
	c70:
			pop ax bx cx
			push ax cx
			
			mov cx, [currentX]
			mov dx, [currentY]
			
			push ax
			
			cmp ax, 'w'
			jnz gtd0
			add cx, 12
			dec dx
	gtd0:	cmp ax, 'a'
			jnz gtd1
			add dx, 12
			dec cx
	gtd1:	cmp ax, 's'
			jnz gtd2
			add cx, 12
			add dx, 11
	gtd2:	cmp ax, 'd'
			jnz gtd3
			add dx, 12
			add cx, 11
			
	gtd3:	
	gdt00:	push ax
	dt9:	pop ax
			cmp ax, 'w'
			jnz gtd4
			dec cx
	gtd4:	cmp ax, 'a'
			jnz gtd5
			dec dx
	gtd5:	cmp ax, 's'
			jnz gtd6
			dec cx
	gtd6:	cmp ax, 'd'
			jnz gtd7
			dec dx
	gtd7:	push ax
			
			mov ah, 0dh
			int 10h
			cmp al, 15
			jnz gtd15
			
			
	dt10:	mov di, 0
			sub di, 2
	dt20:	add di, 2
			cmp dfg[di], 0
			jnz dt20
			cmp dfg[di][2], 0
			jnz dt20
			mov dfg[di], cx
			mov dfg[di][2], dx
			cmp di, [gp]
			jc gtd15
			mov gp, di
			add gp, 4
			
	gtd15:	cmp al, 14
			jnz hj0
			call lose
			
	hj0:	pop ax
			
			cmp ax, 'w'
			jnz gtd11
			cmp cx, [currentX]
			jnz gdt00
	gtd11:	cmp ax, 'a'
			jnz gtd12
			cmp dx, [currentY]
			jnz gdt00
	gtd12:	cmp ax, 's'
			jnz gtd13
			cmp cx, [currentX]
			jnz gdt00
	gtd13:	cmp ax, 'd'
			jnz gtd14
			cmp dx, [currentY]
			jz gtd14
			jmp gdt00
	gtd14:
			pop ax
			
			ret
	moveGhost	endp