;--------------PRINT MESSAGE--------------------

printmsg macro msg
    mov ah,9
    mov dx,offset msg
    int 21h
endm printmsg

;--------------READ MESSAGE---------------------

readmsg macro msg
    mov ah,0ah
    mov dx,offset msg
    int 21h
endm readmsg

;--------------checkEQUALITY--------------------

checkEQUALITY MACRO S1,S2 
    MOV CX, 3 
    MOV SI, offset S1  
    MOV DI, offset S2 
    REPE CMPSB
    cmp cx,0     
endm checkEQUALITY

;--------------checkInstructionEQUALITY---------

checkINSEQUALITY MACRO S1,S2 
    MOV CX, 4 
    MOV SI, offset S1  
    MOV DI, offset S2 
    REPE CMPSB
    cmp cx,0     
endm checkINSEQUALITY
;---------Print Hexa---------------------------
printhexa macro num
        mov bx,num
        mov cx,4
        notZero:
        mov dl,bh
        push cx
        mov cl,4
        shr dl,cl
        pop cx
        cmp dl,9
        jle rakam
        add dl,55
        jmp kammel
        rakam: 
        add dl,30h
        kammel:
        push cx
        mov cl,4 
        shl bx,cl
        pop cx
        mov ah,2
        int 21h
        loop notZero
endm printhexa
;-------------------------------------------------
push_all macro                  ;; push all
    push ax
    push bx
    push cx
    push dx
    push si
    push di
    push bp
    push sp
endm push_all   
;;**********  
pop_all macro                  ;; pop all
    pop sp
    pop bp
    pop di
    pop si
    pop dx
    pop cx
    pop bx 
    pop ax 
endm pop_all