include dseg.h

sseg segment stack
    dw 80 dup(?)
sseg ends

cseg segment
assume  cs:cseg, ss:sseg, ds:dseg

    include drawB.h
    include drawP.h
    include DMG.h
    
    number2string proc 
    
        ;FILL BUF WITH DOLLARS
        push si
        mov  cx, 6
        six_dollars:      
        mov  bl, '$'
        mov  [ si ], bl
        inc  si
        loop six_dollars
        pop  si

        mov bx, 10              ;DIGITS ARE EXTRACTED DIVIDING BY 10
        mov cx, 0               ;COUNTER FOR EXTRACTED DIGITS
        mov num2str, ax
        
        cmp ax, 100
        jnc cy0
        inc cx
        
    cy0:cmp ax, 10
        jnc cycle1
        inc cx
    cycle1:       
        mov  dx, 0              ;NECESSARY TO DIVIDE BY BX
        div  bx                 ;DX:AX / 10 = AX:QUOTIENT DX:REMAINDER
        push dx                 ;PRESERVE DIGIT EXTRACTED FOR LATER
        inc  cx                 ;INCREASE COUNTER FOR EVERY DIGIT EXTRACTED
        cmp  ax, 0              ;IF NUMBER IS
        jne  cycle1             ;NOT ZERO, LOOP
        
        mov ax, [num2str]
        cmp ax, 100
        jnc cy1
        push 0
        cmp ax, 10
    cy1:jnc cycle2
        push 0
                                ;NOW RETRIEVE PUSHED DIGITS
    cycle2:  
        pop  dx        
        add  dl, 48             ;CONVERT DIGIT TO CHARACTER
        mov  [si], dl
        inc  si
        loop cycle2  

        ret
    endp
    
    drawT       proc
    

        display_time:          
        ; GET SYSTEM TIME
        mov  ah, 2ch
        int  21h                ; SECONDS RETURN IN DH minuts in cl
        
        cmp  dh, Rsec
        je re                   ; REPEAT UNTIL 1 SECOND PASSED
        mov Rsec, dh
        inc  seconds
        ; CONVERT SECONDS TO STRING  
        xor  ax, ax             ; NUMBER TO CONVERT TO STRING
        mov  al, seconds        ; SECONDS IN AX
        lea  si, buf            ; VARIABLE WHERE STRING WILL BE STORED
        call number2string      ; CALL PROCEDURE THAT CONVERTS NUMBER TO STRING
        ; MOVE CURSOR
        mov  dl, 3              ; X
        mov  dh, 21             ; Y
        mov  ah, 2
        mov  bh, 0
        int  10h  
        ; DISPLAY STRING
        mov  ah, 9
        lea  dx, buf
        int  21h
    re:
        ret
    drawT       endp
    
    drawD       proc
    
        xor  ax, ax
        mov  al, dots   
        lea  si, buf    
        call number2string      
        ; MOVE CURSOR
        mov  dl, 33             ; X
        mov  dh, 21             ; Y
        mov  ah, 2
        mov  bh, 0
        int  10h  
        ; DISPLAY STRING
        mov  ah, 9
        lea  dx, buf
        int  21h
    
        ret
    drawD       endp
    
    win     proc
    
        mov ax, dseg            ;graphic settings
        mov ds, ax
        mov ah, 0
        mov al, 13h
        int 10h 
        
        LEA DX, winS1           ; loading the effective address
        MOV AH, 09H             ; for string display
        INT 21H 

        LEA DX, winS2           ; loading the effective address
        MOV AH, 09H             ; for string display
        INT 21H
        
        mov ah, 8
    wl: int 21h
        cmp al, 27
        jnz wl
        jmp en
    
        ret
    win     endp
    
    lose        proc
    
        mov ax, dseg            ;graphic settings
        mov ds, ax
        mov ah, 0
        mov al, 13h
        int 10h 
        
        LEA DX, loseS1          ; loading the effective address
        MOV AH, 09H             ; for string display
        INT 21H 

        LEA DX, loseS2          ; loading the effective address
        MOV AH, 09H             ; for string display
        INT 21H
        
    ls: mov ah, 8
        int 21h
        cmp al, 27
        jnz ls
        jmp en
    
        ret
    lose        endp

    Start:  
            mov ax, dseg            ;read dseg
            mov ds, ax

            mov ax, dseg            ;graphic settings
            mov ds, ax
            mov ah, 0
            mov al, 13h
            int 10h

            call drawBoard

    game:
            mov ax, [topLeftX]
            mov currentX, ax
            
            mov ax, [topLeftY]
            mov currentY, ax
            
            mov ah, 1
            int 16h                 ;check if input was given
            jz move1

            mov ah, 0
            int 16h                 ;get the input

            cmp al, 27              ;escape
            jnz c4
            jmp en
    c4:
            cmp al, 'w'
            jnz c0
            mov lastB, 'w'
    c0:     
            cmp al, 'a'
            jnz c1
            mov lastB, 'a'
    c1:     
            cmp al, 's'
            jnz c2
            mov lastB, 's'
    c2:     
            cmp al, 'd'
            jnz c3
            mov lastB, 'd'
    c3:
            cmp al, 91              ;], up
            jnz c51
            cmp [dly], 70
            jnc c61
            inc dly
    c51:
            cmp al, 93              ;[, down
            jnz c61
            cmp [dly], 1
            jz c61
            dec dly
    c61:

    
    move1:  mov ah, 0dh                 ;check if keep on moving by checking 4 pixles in the direction
            mov bh, 0

            cmp movTo, 'w'
            jnz c8

            mov dx, [topLeftY]          ;row
            dec dx
            mov cx, [topLeftX]          ;col
            dec cx
            int 10h
            cmp al, 1
            jz c8

            dec dx                      ;row
            int 10h
            cmp al, 1
            jz c8

            add cx, 12                  ;col
            int 10h
            cmp al, 1
            jz c8

            inc dx                      ;row
            int 10h
            cmp al, 1
            jz c8
            
            dec topLeftY
            
            mov bl, 12
            inc cx
    dt0:    dec cx                      ;col
            int 10h
            cmp al, 15
            jz dt1
            dec bl
            jnz dt0
            
            jmp c8
    dt1:    dec dots
            
            push ax bx
            mov ah, 0ch
            mov al, 0
            mov bh, 0
            int 10h
            pop bx ax
            
            cmp cx, [topLeftX]
            jnz dt0
    c8:     
            cmp movTo, 'a'
            jnz c9

            mov dx, [topLeftY]          ;row
            dec dx
            mov cx, [topLeftX]          ;col
            dec cx
            int 10h
            cmp al, 1
            jz c9

            dec cx                      ;col
            int 10h
            cmp al, 1
            jz c9

            add dx, 12                  ;row
            int 10h
            cmp al, 1
            jz c9

            inc cx                      ;col
            int 10h
            cmp al, 1
            jz c9

            dec topLeftX
            
            mov bl, 12
            inc dx
    dt2:    dec dx                      ;row
            int 10h
            cmp al, 15
            jz dt3
            dec bl
            jnz dt2
            
            jmp c9
    dt3:    dec dots
                
            push ax bx
            mov ah, 0ch
            mov al, 0
            mov bh, 0
            int 10h
            pop bx ax
            
            cmp dx, [topLeftY]
            jnz dt2
    c9:     
            cmp movTo, 's'
            jnz c10

            mov dx, [topLeftY]          ;row
            add dx, 11
            mov cx, [topLeftX]          ;col
            dec cx
            int 10h
            cmp al, 1
            jz c10

            inc dx                      ;row
            int 10h
            cmp al, 1
            jz c10

            add cx, 12                  ;col
            int 10h
            cmp al, 1
            jz c10

            dec dx                      ;row
            int 10h
            cmp al, 1
            jz c10

            inc topLeftY
            
            mov bl, 12
            inc cx
    dt4:    dec cx                      ;col
            int 10h
            cmp al, 15
            jz dt5
            dec bl
            jnz dt4
            
            jmp c10
    dt5:    dec dots
                
            push ax bx
            mov ah, 0ch
            mov al, 0
            mov bh, 0
            int 10h
            pop bx ax
            
            cmp cx, [topLeftX]
            jnz dt4
    c10:        
            cmp movTo, 'd'
            jnz c11

            mov dx, [topLeftY]          ;row
            dec dx
            mov cx, [topLeftX]          ;col
            add cx, 11
            int 10h
            cmp al, 1
            jz c11

            inc cx                      ;col
            int 10h
            cmp al, 1
            jz c11

            add dx, 12                  ;row
            int 10h
            cmp al, 1
            jz c11

            dec cx                      ;col
            int 10h
            cmp al, 1
            jz c11

            inc topLeftX
            
            mov bl, 12
            inc dx
    dt7:    dec dx                      ;col
            int 10h
            cmp al, 15
            jz dt8
            dec bl
            jnz dt7
            
            jmp c11
    dt8:    dec dots
                
            push ax bx
            mov ah, 0ch
            mov al, 0
            mov bh, 0
            int 10h
            pop bx ax
            
            cmp dx, [topLeftY]
            jnz dt7
    c11:
    move0:  mov al, lastB               ;check if can move to the user input
            cmp al, movTo
            jnz c100
            jmp c7
    c100:
            mov ah, 0dh
            mov bh, 0

            cmp lastB, 'w'
            jnz c41

            mov dx, [currentY]          ;row
            dec dx
            mov cx, [currentX]          ;col
            dec cx
            int 10h
            cmp al, 1
            jz c41

            dec dx                      ;row
            int 10h
            cmp al, 1
            jz c41

            add cx, 6                   ;col
            int 10h
            cmp al, 1
            jz c41
            
            inc dx                      ;row
            int 10h
            cmp al, 1
            jz c41
            
            add cx, 6                   ;col
            int 10h
            cmp al, 1
            jz c41
            
            dec dx                      ;row
            int 10h
            cmp al, 1
            jz c41

            mov cl, lastB
            mov movTo, cl
            
            mov dx, [currentX]
            mov topLeftX, dx
            
            mov dx, [currentY]
            mov topLeftY, dx
    c41:        
            cmp lastB, 'a'
            jnz c5

            mov dx, [currentY]          ;row
            dec dx
            mov cx, [currentX]          ;col
            dec cx
            int 10h
            cmp al, 1
            jz c5

            dec cx                      ;col
            int 10h
            cmp al, 1
            jz c5

            add dx, 6                   ;row
            int 10h
            cmp al, 1
            jz c5

            inc cx                      ;col
            int 10h
            cmp al, 1
            jz c5
            
            add dx, 6                   ;row
            int 10h
            cmp al, 1
            jz c5
            
            dec cx                      ;col
            int 10h
            cmp al, 1
            jz c5

            mov cl, lastB
            mov movTo, cl
            
            mov dx, [currentX]
            mov topLeftX, dx
            
            mov dx, [currentY]
            mov topLeftY, dx
    c5:     
            cmp lastB, 's'
            jnz c6

            mov dx, [currentY]          ;row
            add dx, 11
            mov cx, [currentX]          ;col
            dec cx
            int 10h
            cmp al, 1
            jz c6

            inc dx                      ;row
            int 10h
            cmp al, 1
            jz c6

            add cx, 6                   ;col
            int 10h
            cmp al, 1
            jz c6

            dec dx                      ;row
            int 10h
            cmp al, 1
            jz c6
            
            add cx, 6                   ;col
            int 10h
            cmp al, 1
            jz c6
            
            inc dx                      ;row
            int 10h
            cmp al, 1
            jz c6

            mov cl, lastB
            mov movTo, cl
            
            mov dx, [currentX]
            mov topLeftX, dx
            
            mov dx, [currentY]
            mov topLeftY, dx
    c6:     
            cmp lastB, 'd'
            jnz c7

            mov dx, [currentY]          ;row
            dec dx
            mov cx, [currentX]          ;col
            add cx, 11
            int 10h
            cmp al, 1
            jz c7

            inc cx                      ;col
            int 10h
            cmp al, 1
            jz c7

            add dx, 6                   ;row
            int 10h
            cmp al, 1
            jz c7

            dec cx                      ;row
            int 10h
            cmp al, 1
            jz c7
            
            add dx, 6                   ;row
            int 10h
            cmp al, 1
            jz c7
            
            inc cx                      ;col
            int 10h
            cmp al, 1
            jz c7

            mov cl, lastB
            mov movTo, cl
            
            mov dx, [currentX]
            mov topLeftX, dx
            
            mov dx, [currentY]
            mov topLeftY, dx
    c7:
            call drawPacman
            call drawT
            call drawD
            
            
            mov si, 0
            sub si, 4
    gh0:    add si, 4
            cmp si, gp
            jnz gh000
            jmp gh
    gh000:  
            cmp dfg[si], 0
            jz gh0
            cmp dfg[si][2], 0
            jz gh0
            mov cx, dfg[si]
            mov dx, dfg[si][2]
            
            mov ax, [topLeftXr]
            add ax, 11
            sub cx, ax
            jnc gh2
            mov cx, dfg[si]
            sub cx, [topLeftXr]
            jc gh2
            
    gh1:    mov ax, [topLeftYr]
            add ax, 11
            sub dx, ax
            jnc gh2
            mov dx, dfg[si][2]
            sub dx, [topLeftYr]
            jc gh2
            jmp gh0
            
    gh2:    mov cx, dfg[si]
            mov dx, dfg[si][2]
            
            mov ax, [topLeftXp]
            add ax, 11
            sub cx, ax
            jnc gh4
            mov cx, dfg[si]
            sub cx, [topLeftXp]
            jc gh4
            
    gh3:    mov ax, [topLeftYp]
            add ax, 11
            sub dx, ax
            jnc gh4
            mov dx, dfg[si][2]
            sub dx, [topLeftYp]
            jc gh4
            jmp gh0
            
    gh4:    mov cx, dfg[si]
            mov dx, dfg[si][2]
            
            mov ax, [topLeftXc]
            add ax, 11
            sub cx, ax
            jnc gh6
            mov cx, dfg[si]
            sub cx, [topLeftXc]
            jc gh6
            
    gh5:    mov ax, [topLeftYc]
            add ax, 11
            sub dx, ax
            jnc gh6
            mov dx, dfg[si][2]
            sub dx, [topLeftYc]
            jc gh6
            jmp gh0
    gh6:
            
            mov cx, dfg[si]
            mov dx, dfg[si][2]
            
            mov ax, [topLeftXo]
            add ax, 11
            sub cx, ax
            jnc gh8
            mov cx, dfg[si]
            sub cx, [topLeftXo]
            jc gh8
            
    gh7:    mov ax, [topLeftYo]
            add ax, 11
            sub dx, ax
            jnc gh8
            mov dx, dfg[si][2]
            sub dx, [topLeftYo]
            jc gh8
            jmp gh0

    gh8:    mov cx, dfg[si]
            mov dx, dfg[si][2]
            mov ah, 0ch
            mov al, 15
            mov bh, 0
            int 10h
            
            mov dfg[si], 0
            mov dfg[si][2], 0
            jmp gh0
            
    gh:
    kl1:    cmp gp, 0
            jz kl0
            mov si, gp
            sub si, 4
            cmp dfg[si], 0
            jnz kl0
            cmp dfg[si][2], 0
            jnz kl0
            sub gp, 4
            jmp kl1
    kl0:
            
            
            push 4  topLeftYr topLeftXr         ;red
            call drawGhost
            
            mov al, [movToR]
            mov ah, 0
            push ax topLeftYr topLeftXr
            call moveGhost
            pop ax
            
            mov movToR, al
            cmp movToR, 'w'
            jnz f00
            dec topLeftYr
    f00:    cmp movToR, 'a'
            jnz f01
            dec topLeftXr
    f01:    cmp movToR, 's'
            jnz f02
            inc topLeftYr
    f02:    cmp movToR, 'd'
            jnz f03
            inc topLeftXr
    f03:    
            push 12  topLeftYo topLeftXo            ;orange
            call drawGhost
            
            mov al, [movToo]
            mov ah, 0
            push ax topLeftYo topLeftXo
            call moveGhost
            pop ax
            
            mov movToo, al
            cmp movToo, 'w'
            jnz f04
            dec topLeftYo
    f04:    cmp movToo, 'a'
            jnz f05
            dec topLeftXo
    f05:    cmp movToo, 's'
            jnz f06
            inc topLeftYo
    f06:    cmp movToo, 'd'
            jnz f07
            inc topLeftXo
    f07:    
    
            push 13 topLeftYp topLeftXp         ;pink
            call drawGhost
            
            mov al, [movTop]
            mov ah, 0
            push ax topLeftYp topLeftXp
            call moveGhost
            pop ax
            
            mov movTop, al
            cmp movTop, 'w'
            jnz f08
            dec topLeftYp
    f08:    cmp movTop, 'a'
            jnz f09
            dec topLeftXp
    f09:    cmp movTop, 's'
            jnz f10
            inc topLeftYp
    f10:    cmp movTop, 'd'
            jnz f11
            inc topLeftXp
    f11:    
    
            push 3  topLeftYc topLeftXc         ;cyan
            call drawGhost
            
            mov al, [movToc]
            mov ah, 0
            push ax topLeftYc topLeftXc
            call moveGhost
            pop ax
            
            mov movToc, al
            cmp movToc, 'w'
            jnz f12
            dec topLeftYc
    f12:    cmp movToc, 'a'
            jnz f13
            dec topLeftXc
    f13:    cmp movToc, 's'
            jnz f14
            inc topLeftYc
    f14:    cmp movToc, 'd'
            jnz f15
            inc topLeftXc
    f15:    
            
            cmp topLeftX, 320   ;wrap around
            jng qw1
            mov topLeftX, 1
            inc topLeftY
    qw1:
            mov ax, 0
            sub ax, 10
            cmp topLeftX, ax
            jnl qw2
            mov topLeftX, 310
            dec topLeftY
    qw2:    
            cmp dots, 0        ;win check
            jnz nd
            call win
    nd:     
            mov cl, [dly]
    dly1:   mov bx, 2000       ;delay
    dly0:   mov ax, bx
            dec bx
            jnz dly0
            dec cl
            jnz dly1

            jmp game
    en:
            int 3
cseg    ends
end     Start