	drawX		proc 
			pop bx cx dx ax
			push bx
			mov untilX, ax

			mov ah, 0ch								
			mov al, 1
			mov bh, 0

	a:		inc cx
			int 10h				
			cmp cx, [untilX]
			jnz a

			ret
	drawX		endp

	drawY		proc 
			pop bx cx dx ax
			push bx
			mov untilY, ax

			mov ah, 0ch								
			mov al, 1
			mov bh, 0

	b:		inc dx
			int 10h				
			cmp dx, [untilY]
			jnz b

			ret
	drawY		endp
	
	drawXD		proc 
			pop bx cx dx ax
			push bx
			mov untilX, ax

			mov ah, 0ch								
			mov al, 15
			mov bh, 0
			
			sub cx, 10
	c:		add cx, 10
			cmp cx, [untilX]
			jnc c00
			int 10h
			inc dots
			jmp c
	c00:
			ret
	drawXD		endp
	
	drawYD		proc 
			pop bx cx dx ax
			push bx
			mov untilY, ax

			mov ah, 0ch								
			mov al, 15
			mov bh, 0
			
			sub dx, 11
	d:		add dx, 11
			cmp dx, [untilY]
			jnc d00
			int 10h
			inc dots
			jmp d
	d00:
			ret
	drawYD		endp

	drawBoard	proc 
			push ax bx cx dx		
			
			sub dots, 5
			
			mov cx, 1				;col			upper line, going down by each line
			mov dx, 1				;row				
			mov ax, 317				;untilX
			push ax dx cx
			call drawX

			mov cx, 5				;col			left line
			mov dx, 5				;row			
			mov ax, 152
			push ax dx cx
			call drawX

			mov cx, 163				;col			right line
			mov dx, 5				;row				
			mov ax, 312
			push ax dx cx
			call drawX

			mov cx, 152				;col			left vertical line 
			mov dx, 5				;row			
			mov ax, 28	
			push ax dx cx
			call drawY

			mov cx, 164				;col			right vertical line 
			mov dx, 5				;row			
			mov ax, 28	
			push ax dx cx
			call drawY

			mov cx, 2				;col			left most vertical line
			mov dx, 1				;row
			mov ax, 71	
			push ax dx cx
			call drawY

			mov cx, 317				;col			right most vertical line
			mov dx, 1				;row			
			mov ax, 71
			push ax dx cx
			call drawY

			mov cx, 6				;col			close to left most vertical line
			mov dx, 5				;row				
			mov ax, 67
			push ax dx cx
			call drawY

			mov cx, 313				;col			close to right most vertical line
			mov dx, 5				;row
			mov ax, 67
			push ax dx cx
			call drawY
			
			
			
			mov cx, 2				;col			start of out
			mov dx, 71				;row		
			mov ax, 52
			push ax dx cx
			call drawX
			
			mov cx, 6				;col			start of out
			mov dx, 67				;row
			mov ax, 56
			push ax dx cx
			call drawX
			
			mov cx, 260				;col			start of out
			mov dx, 67				;row
			mov ax, 312
			push ax dx cx
			call drawX
			
			mov cx, 264				;col			start of out
			mov dx, 71				;row		
			mov ax, 316
			push ax dx cx
			call drawX
			
			mov cx, 53				;col			
			mov dx, 70				;row
			mov ax, 92
			push ax dx cx
			call drawY

			mov cx, 57				;col			
			mov dx, 66				;row
			mov ax, 96
			push ax dx cx
			call drawY
			
			mov cx, 264				;col			
			mov dx, 70				;row				
			mov ax, 91
			push ax dx cx
			call drawY

			mov cx, 260				;col			
			mov dx, 66				;row
			mov ax, 95
			push ax dx cx
			call drawY
			
			mov cx, 2				;col			start of out
			mov dx, 92				;row		
			mov ax, 52
			push ax dx cx
			call drawX
			
			mov cx, 2				;col			start of out
			mov dx, 96				;row
			mov ax, 56
			push ax dx cx
			call drawX
			
			mov cx, 260				;col			start of out
			mov dx, 95				;row
			mov ax, 316
			push ax dx cx
			call drawX
			
			mov cx, 264				;col			start of out
			mov dx, 91				;row		
			mov ax, 316
			push ax dx cx
			call drawX
			
			
			
			mov cx, 2				;col			end of out
			mov dx, 114				;row		
			mov ax, 52
			push ax dx cx
			call drawX
			
			mov cx, 2				;col			end of out
			mov dx, 110				;row
			mov ax, 56
			push ax dx cx
			call drawX
			
			mov cx, 260				;col			end of out
			mov dx, 109				;row
			mov ax, 316
			push ax dx cx
			call drawX
			
			mov cx, 264				;col			end of out
			mov dx, 113				;row		
			mov ax, 316
			push ax dx cx
			call drawX
			
			mov cx, 53				;col			
			mov dx, 113				;row
			mov ax, 133
			push ax dx cx
			call drawY

			mov cx, 57				;col			
			mov dx, 109				;row
			mov ax, 137
			push ax dx cx
			call drawY
			
			mov cx, 264				;col			
			mov dx, 112				;row				
			mov ax, 133
			push ax dx cx
			call drawY

			mov cx, 260				;col			
			mov dx, 108				;row
			mov ax, 137
			push ax dx cx
			call drawY
			
			mov cx, 2				;col			end of out
			mov dx, 133				;row		
			mov ax, 52
			push ax dx cx
			call drawX
			
			mov cx, 6				;col			end of out
			mov dx, 137				;row
			mov ax, 56
			push ax dx cx
			call drawX
			
			mov cx, 260				;col			end of out
			mov dx, 137				;row
			mov ax, 311
			push ax dx cx
			call drawX
			
			mov cx, 264				;col			end of out
			mov dx, 133				;row		
			mov ax, 315
			push ax dx cx
			call drawX
			
			
			
			mov cx, 2				;col			lowest vertical lines, going from left to right		
			mov dx, 132				;row
			mov ax, 198
			push ax dx cx
			call drawY

			mov cx, 6				;col			
			mov dx, 136				;row
			mov ax, 194
			push ax dx cx
			call drawY
			
			mov cx, 316				;col			
			mov dx, 132				;row				
			mov ax, 198
			push ax dx cx
			call drawY

			mov cx, 312				;col			
			mov dx, 136				;row
			mov ax, 194
			push ax dx cx
			call drawY
			
			mov cx, 2				;col			lowest line
			mov dx, 198				;row		
			mov ax, 315
			push ax dx cx
			call drawX
			
			mov cx, 6				;col			closest to lowest line 
			mov dx, 194				;row
			mov ax, 96
			push ax dx cx
			call drawX
			
			mov cx, 96				;col			closest to lowest line up
			mov dx, 181				;row
			mov ax, 194
			push ax dx cx
			call drawY
			
			mov cx, 96				;col			closest to lowest line 
			mov dx, 182				;row
			mov ax, 222
			push ax dx cx
			call drawX
			
			mov cx, 222				;col			closest to lowest line down
			mov dx, 182				;row
			mov ax, 194
			push ax dx cx
			call drawY
			
			mov cx, 222				;col			closest to lowest line 
			mov dx, 194				;row
			mov ax, 311
			push ax dx cx
			call drawX

			mov cx, 152				;col			most upper connection
			mov dx, 28				;row
			mov ax, 163
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 18				;row			most left upper cube, going to right
			mov cx, 20				;col
			mov ax, 28
			push ax dx cx
			call drawY

			mov ax, 57					
			push ax dx cx
			call drawX

			mov dx, 18				;row
			mov ax, 27
			push ax dx cx
			call drawY

			mov dx, 19				;row
			mov cx, 20				;col
			mov ax, 56					
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 18				;row			cube
			mov cx, 71				;col
			mov ax, 28
			push ax dx cx
			call drawY

			mov ax, 138					
			push ax dx cx
			call drawX

			mov dx, 18				;row
			mov ax, 27
			push ax dx cx
			call drawY

			mov dx, 19				;row
			mov cx, 71				;col
			mov ax, 137				
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 18				;row			cube
			mov cx, 178				;col
			mov ax, 28
			push ax dx cx
			call drawY

			mov ax, 246					
			push ax dx cx
			call drawX

			mov dx, 18				;row
			mov ax, 27
			push ax dx cx
			call drawY

			mov dx, 19				;row
			mov cx, 178				;col
			mov ax, 245					
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 18				;row			cube
			mov cx, 260				;col
			mov ax, 28
			push ax dx cx
			call drawY

			mov ax, 299					
			push ax dx cx
			call drawX

			mov dx, 18				;row
			mov ax, 27
			push ax dx cx
			call drawY

			mov dx, 19				;row
			mov cx, 260				;col
			mov ax, 298					
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 41				;row			new line, cube
			mov cx, 20				;col
			mov ax, 53
			push ax dx cx
			call drawY

			mov ax, 57					
			push ax dx cx
			call drawX

			mov dx, 41				;row
			mov ax, 52
			push ax dx cx
			call drawY

			mov dx, 42				;row
			mov cx, 20				;col
			mov ax, 56					
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 41				;row			cube
			mov cx, 260				;col
			mov ax, 53
			push ax dx cx
			call drawY

			mov ax, 299					
			push ax dx cx
			call drawX

			mov dx, 41				;row
			mov ax, 52
			push ax dx cx
			call drawY

			mov dx, 42				;row
			mov cx, 260				;col
			mov ax, 298					
			push ax dx cx
			call drawX

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 41				;row		left plus
			mov cx, 71				;col
	ai:		inc dx
			int 10h				
			cmp dx, 96
			jnz	ai

	aj:		inc cx					;col
			int 10h				
			cmp cx, 82
			jnz	aj

	ak:		dec dx					;row
			int 10h				
			cmp dx, 76
			jnz	ak

	al0:	inc cx					;col
			int 10h				
			cmp cx, 138
			jnz	al0

	am:		dec dx					;row
			int 10h				
			cmp dx, 66
			jnz	am

	an:		dec cx					;col
			int 10h				
			cmp cx, 82
			jnz	an

	ao:		dec dx					;row
			int 10h				
			cmp dx, 42
			jnz	ao

	ap:		dec cx					;col
			int 10h				
			cmp cx, 72
			jnz	ap

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 41				;row		right plus
			mov cx, 246				;col
	aq:		inc dx
			int 10h				
			cmp dx, 95
			jnz	aq

	ar:		dec cx					;col
			int 10h				
			cmp cx, 236
			jnz	ar

	as:		dec dx					;row
			int 10h				
			cmp dx, 76
			jnz	as

	at:		dec cx					;col
			int 10h				
			cmp cx, 179
			jnz	at

	au:		dec dx					;row
			int 10h				
			cmp dx, 66
			jnz	au

	av:		inc cx					;col
			int 10h				
			cmp cx, 236
			jnz	av

	aw:		dec dx					;row
			int 10h				
			cmp dx, 42
			jnz	aw

	ax0:	inc cx					;col
			int 10h				
			cmp cx, 245
			jnz	ax0

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 41				;row			up plus	
			mov cx, 96				;col
	ay:		inc dx
			int 10h				
			cmp dx, 52
			jnz	ay

	az:		inc cx					;col
			int 10h				
			cmp cx, 152
			jnz	az
			
	ba:		inc dx					;row
			int 10h				
			cmp dx, 76
			jnz	ba

	bb:		inc cx					;col
			int 10h				
			cmp cx, 165
			jnz	bb

	bc:		dec dx					;row
			int 10h				
			cmp dx, 52
			jnz	bc

	bd:		inc cx					;col
			int 10h				
			cmp cx, 222
			jnz bd

	be:		dec dx					;row
			int 10h				
			cmp dx, 42
			jnz	be

	bf:		dec cx					;col
			int 10h				
			cmp cx, 97
			jnz bf

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 89				;row			cube
			mov cx, 96				;col
			mov ax, 120
			push ax dx cx
			call drawY

			mov ax, 222					
			push ax dx cx
			call drawX

			mov dx,	89				;row
			mov ax, 119
			push ax dx cx
			call drawY

			mov dx, 90				;row
			mov cx, 96				;col
			mov ax, 221					
			push ax dx cx
			call drawX
			
			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 109				;row		left down plus 
			mov cx, 71				;col
	bi:		inc dx
			int 10h				
			cmp dx, 180
			jnz	bi

	bj:		inc cx					;col
			int 10h				
			cmp cx, 82
			jnz	bj

	bk:		dec dx					;row
			int 10h				
			cmp dx, 168
			jnz	bk

	bl0:	inc cx					;col
			int 10h				
			cmp cx, 138
			jnz	bl0

	bm:		dec dx					;row
			int 10h				
			cmp dx, 158
			jnz	bm

	bn:		dec cx					;col
			int 10h				
			cmp cx, 82
			jnz	bn

	bo:		dec dx					;row
			int 10h				
			cmp dx, 110
			jnz	bo

	bp1:	dec cx					;col
			int 10h				
			cmp cx, 72
			jnz	bp1

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 108				;row		right down plus
			mov cx, 246				;col
	bq:		inc dx
			int 10h				
			cmp dx, 180
			jnz	bq

	br:		dec cx					;col
			int 10h				
			cmp cx, 236
			jnz	br

	bs:		dec dx					;row
			int 10h				
			cmp dx, 168
			jnz	bs

	bt1:	dec cx					;col
			int 10h				
			cmp cx, 179
			jnz	bt1

	bu:		dec dx					;row
			int 10h				
			cmp dx, 158
			jnz	bu

	bv:		inc cx					;col
			int 10h				
			cmp cx, 236
			jnz	bv

	bw:		dec dx					;row
			int 10h				
			cmp dx, 109
			jnz	bw

	bx0:	inc cx					;col
			int 10h				
			cmp cx, 245
			jnz	bx0

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 133				;row			up down plus	
			mov cx, 96				;col
	by:		inc dx
			int 10h				
			cmp dx, 144
			jnz	by

	bz:		inc cx					;col
			int 10h				
			cmp cx, 152
			jnz	bz
			
	ca:		inc dx					;row
			int 10h				
			cmp dx, 168
			jnz	ca

	cb:		inc cx					;col
			int 10h				
			cmp cx, 165
			jnz	cb

	cc:		dec dx					;row
			int 10h				
			cmp dx, 144
			jnz	cc

	cd:		inc cx					;col
			int 10h				
			cmp cx, 222
			jnz cd

	ce:		dec dx					;row
			int 10h				
			cmp dx, 134
			jnz	ce

	cf:		dec cx					;col
			int 10h				
			cmp cx, 97
			jnz cf

			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 150				;row			down left cube
			mov cx, 20				;col
			mov ax, 180
			push ax dx cx
			call drawY

			mov ax, 57					
			push ax dx cx
			call drawX

			mov dx, 150				;row
			mov ax, 180
			push ax dx cx
			call drawY

			mov dx, 151				;row
			mov cx, 20				;col
			mov ax, 56					
			push ax dx cx
			call drawX
			
			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

			mov dx, 150				;row			down right cube
			mov cx, 260				;col
			mov ax, 180
			push ax dx cx
			call drawY

			mov ax, 298					
			push ax dx cx
			call drawX

			mov dx, 150				;row
			mov ax, 180
			push ax dx cx
			call drawY

			mov dx, 151				;row
			mov cx, 260				;col
			mov ax, 297					
			push ax dx cx
			call drawX
			
			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
			
			mov dx, 11				;row			1 of first line
			mov cx, 24				;col
			mov ax, 64					
			push ax dx cx
			call drawXD
			
			mov dx, 11				;row			2 of first line
			mov cx, 75				;col
			mov ax, 145					
			push ax dx cx
			call drawXD
			
			mov dx, 11				;row			3 of first line
			mov cx, 182				;col
			mov ax, 252					
			push ax dx cx
			call drawXD
			
			mov dx, 11				;row			4 of first line
			mov cx, 265				;col
			mov ax, 305					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			1 of second line
			mov cx, 24				;col
			mov ax, 64					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			2 of second line
			mov cx, 75				;col
			mov ax, 145					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			2.5 of second line
			mov cx, 153				;col
			mov ax, 170					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			3 of second line
			mov cx, 182				;col
			mov ax, 252					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			4 of second line
			mov cx, 265				;col
			mov ax, 305					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			point
			mov cx, 145				;col
			mov ax, 146					
			push ax dx cx
			call drawXD
			
			mov dx, 34				;row			point
			mov cx, 172				;col
			mov ax, 173					
			push ax dx cx
			call drawXD
			
			mov dx, 60				;row			1 of third line
			mov cx, 24				;col
			mov ax, 64					
			push ax dx cx
			call drawXD
			
			mov dx, 60				;row			2 of third line
			mov cx, 265				;col
			mov ax, 305					
			push ax dx cx
			call drawXD
			
			mov dx, 60				;row			point
			mov cx, 14				;col
			mov ax, 15					
			push ax dx cx
			call drawXD
			
			mov dx, 60				;row			point
			mov cx, 305				;col
			mov ax, 306					
			push ax dx cx
			call drawXD
			
			mov dx, 11				;row			1 upper vertical line
			mov cx, 14				;col
			mov ax, 60					
			push ax dx cx
			call drawYD
			
			mov dx, 11				;row			2 upper vertical line
			mov cx, 64				;col
			mov ax, 181					
			push ax dx cx
			call drawYD
			
			mov dx, 11				;row			3 upper vertical line
			mov cx, 145				;col
			mov ax, 30					
			push ax dx cx
			call drawYD
			
			mov dx, 11				;row			4 upper vertical line
			mov cx, 172				;col
			mov ax, 30					
			push ax dx cx
			call drawYD
			
			mov dx, 11				;row			5 upper vertical line
			mov cx, 253				;col
			mov ax, 181					
			push ax dx cx
			call drawYD
			
			mov dx, 11				;row			6 upper vertical line
			mov cx, 305				;col
			mov ax, 60					
			push ax dx cx
			call drawYD
			
			mov dx, 47				;row			point
			mov cx, 87				;col
			mov ax, 88					
			push ax dx cx
			call drawXD
			
			mov dx, 47				;row			point
			mov cx, 230				;col
			mov ax, 231					
			push ax dx cx
			call drawXD
			
			mov dx, 59				;row			1 of up plus
			mov cx, 87				;col
			mov ax, 150					
			push ax dx cx
			call drawXD
			
			mov dx, 59				;row			2 of up plus
			mov cx, 170				;col
			mov ax, 235					
			push ax dx cx
			call drawXD
			
			mov dx, 72				;row			point
			mov cx, 147				;col
			mov ax, 148					
			push ax dx cx
			call drawXD
			
			mov dx, 72				;row			point
			mov cx, 170				;col
			mov ax, 171					
			push ax dx cx
			call drawXD
			
			mov dx, 84				;row			up center cube
			mov cx, 97				;col
			mov ax, 225					
			push ax dx cx
			call drawXD
			
			mov dx, 103				;row			point
			mov cx, 77				;col
			mov ax, 78					
			push ax dx cx
			call drawXD
			
			mov dx, 103				;row			point
			mov cx, 241				;col
			mov ax, 242					
			push ax dx cx
			call drawXD
			
			mov dx, 127				;row			down center cube
			mov cx, 97				;col
			mov ax, 225					
			push ax dx cx
			call drawXD
			
			mov dx, 151				;row			1 of down plus
			mov cx, 97				;col
			mov ax, 150					
			push ax dx cx
			call drawXD
			
			mov dx, 151				;row			2 of down plus
			mov cx, 170				;col
			mov ax, 225					
			push ax dx cx
			call drawXD
			
			mov dx, 163				;row			point
			mov cx, 147				;col
			mov ax, 148					
			push ax dx cx
			call drawXD
			
			mov dx, 163				;row			point
			mov cx, 170				;col
			mov ax, 171					
			push ax dx cx
			call drawXD
			
			mov dx, 144				;row			1 of fourth line
			mov cx, 24				;col
			mov ax, 64					
			push ax dx cx
			call drawXD
			
			mov dx, 144				;row			2 of fourth line
			mov cx, 265				;col
			mov ax, 305					
			push ax dx cx
			call drawXD
			
			mov dx, 175				;row			lowest line
			mov cx, 89				;col
			mov ax, 235					
			push ax dx cx
			call drawXD
			
			mov dx, 188				;row			1 of fifth line
			mov cx, 24				;col
			mov ax, 90					
			push ax dx cx
			call drawXD
			
			mov dx, 188				;row			2 of fifth line
			mov cx, 229				;col
			mov ax, 295					
			push ax dx cx
			call drawXD
			
			mov dx, 188				;row			point
			mov cx, 89				;col
			mov ax, 90					
			push ax dx cx
			call drawXD
			
			mov dx, 188				;row			point
			mov cx, 297				;col
			mov ax, 298					
			push ax dx cx
			call drawXD
			
			mov dx, 84				;row			left vertical cube
			mov cx, 89				;col
			mov ax, 160					
			push ax dx cx
			call drawYD
			
			mov dx, 84				;row			right vertical cube
			mov cx, 229				;col
			mov ax, 160					
			push ax dx cx
			call drawYD
			
			mov dx, 144				;row			5 upper vertical line
			mov cx, 13				;col
			mov ax, 190					
			push ax dx cx
			call drawYD
			
			mov dx, 144				;row			6 upper vertical line
			mov cx, 305				;col
			mov ax, 190					
			push ax dx cx
			call drawYD

			pop dx cx bx ax
			ret
	drawBoard endp