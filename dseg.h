dseg segment
	pUnStk		db 	0,0,0,0,0,1,1,1,0,0,0
				db 	0,0,0,1,1,1,1,1,1,1,0
				db 	0,0,1,1,1,1,1,1,1,1,1
				db 	0,0,1,1,1,1,1,1,1,0,0
				db 	0,1,1,1,1,1,1,0,0,0,0
				db 	0,1,1,1,1,0,0,0,0,0,0
				db 	0,1,1,1,1,1,1,0,0,0,0
				db 	0,0,1,1,1,1,1,1,1,0,0
				db 	0,0,1,1,1,1,1,1,1,1,1
				db 	0,0,0,1,1,1,1,1,1,1,0
				db	0,0,0,0,0,1,1,1,0,0,0

	pStkR_O		db	5,3,3,255,3,7,1,255,2,9,255,2,7,2,255,1,6,4,255,1,4,6,255,1,6,4,255,2,7,2,255,2,9,255,3,7,1,255,5,3,3,255
	arrR_O		dw	$-pStkR_O-1
	pStkL_O		db	3,3,5,255,1,7,3,255,0,9,2,255,2,7,2,255,4,6,1,255,6,4,1,255,4,6,1,255,2,7,2,255,0,9,2,255,1,7,3,255,3,3,5,255
	arrL_O		dw	$-pStkL_O-1
	pStkU_O		db	2,1,5,1,2,255,1,2,5,2,1,255,1,3,3,3,1,255,0,4,3,4,255,0,5,1,5,255,0,5,1,5,255,1,9,1,255,1,9,1,255,2,7,2,255,4,3,4,255,11,255
	arrU_O		dw	$-pStkU_O-1
	pStkD_O		db	11,255,4,3,4,255,2,7,2,255,1,9,1,255,1,9,1,255,0,5,1,5,255,0,5,1,5,255,0,4,3,4,255,1,3,3,3,1,255,1,2,5,2,1,255,2,1,5,1,2,255
	arrD_O		dw	$-pStkD_O-1
			
	topLeftX	dw	150
	topLeftY	dw	122

	currentX	dw	?
	currentY	dw	?
	
	untilX		dw	?
	untilY		dw	?
	
	movTo		db	'a'				;'w'-119, 'a'-97, 's'-115, 'd'-100
	lastB		db	'a'
	
	Ghost		db 	0,0,0,0,0,0,0,0,0,0,0
				db 	0,0,0,0,1,1,1,0,0,0,0
				db 	0,0,1,1,1,1,1,1,1,0,0
				db 	0,1,1,0,0,1,0,0,1,1,0
				db 	0,1,1,0,0,1,0,0,1,1,0
				db 	0,1,1,1,1,1,1,1,1,1,0
				db 	0,1,1,1,1,1,1,1,1,1,0
				db 	0,1,1,1,1,1,1,1,1,1,0
				db 	0,1,1,0,1,1,1,0,1,1,0
				db 	0,1,0,0,0,1,0,0,0,1,0
				db 	0,0,0,0,0,0,0,0,0,0,0
				
	gStk		db	11,255,4,3,4,255,2,7,2,255,1,2,2,1,2,2,1,255,1,2,2,1,2,2,1,255,1,9,1,255,1,9,1,255,1,9,1,255,1,2,1,3,1,2,1,255,1,1,3,1,3,1,1,255,11,255
	arrG		dw	$-gStk-1
	dpg			dw	?

	
	topLeftXr	dw	110				;red
	topLeftYr	dw	30;79

	movToR		db	'd'
	
	topLeftXc	dw	140				;cyan
	topLeftYc	dw	79
	
	movToC		db	'd'
	
	topLeftXp	dw	160				;pink
	topLeftYp	dw	79

	movToP		db	'a'
	
	topLeftXo	dw	190				;orange
	topLeftYo	dw	30;79
	
	movToO		db	'a'
	
	dly			db	21
	dots		db	0
	num2str		dw	?
	
	buf    		db	6 dup (?)
	seconds		db	0
	Rsec		db	0
	
	dfg			dw	128 dup (?)
	gp			dw	0
	
	winS1		db	'you win $'
	winS2		db	'press escape to exit $'
	
	loseS1		db	'you lose $'
	loseS2		db	'press escape to exit $'

dseg ends