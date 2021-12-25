;-----------DETECT REGISTER DESTINATION---------
CheckDestination macro des
    local Check_BX
    local Check_CX
    local Check_DX
    local Check_SI
    local Check_DI
    local Check_BP
    local Check_AL
    local Check_AH
    local Check_BL
    local Check_BH
    local Check_CL
    local Check_CH
    local Check_DL
    local Check_DH
    local FoundDestination
    checkEQUALITY des,ax_str
    jnz Check_BX
    mov bx,offset AXREG
    mov checkDesSize,2 
    jmp FoundDestination

    Check_BX:
    checkEQUALITY des,bx_str
    jnz Check_CX
    mov bx,offset BXREG
    mov checkDesSize,2 
    jmp FoundDestination

    Check_CX:
    checkEQUALITY des,cx_str
    jnz Check_DX
    mov bx,offset CXREG
    mov checkDesSize,2 
    jmp FoundDestination

    Check_DX:
    checkEQUALITY des,dx_str
    jnz Check_SI
    mov bx,offset DXREG
    mov checkDesSize,2 
    jmp FoundDestination

    Check_SI:
    checkEQUALITY des,si_str
    jnz Check_DI
    mov bx,offset SIREG
    mov checkDesSize,2 
    jmp FoundDestination

    Check_DI:
    checkEQUALITY des,di_str
    jnz Check_BP
    mov bx,offset DIREG
    mov checkDesSize,2 
    jmp FoundDestination

    Check_BP:
    checkEQUALITY des,bp_str
    jnz Check_AL
    mov bx,offset BPREG
    mov checkDesSize,2 
    jmp FoundDestination
    
    Check_AL:
    checkEQUALITY des,al_str
    jnz Check_AH
    mov bx,offset ALREG
    mov checkDesSize,1 
    jmp FoundDestination
    
    Check_AH:
    checkEQUALITY des,ah_str
    jnz Check_BL
    mov bx,offset AHREG
    mov checkDesSize,1 
    jmp FoundDestination

    Check_BL:
    checkEQUALITY des,bl_str
    jnz Check_BH  
    mov bx,offset BLREG
    mov checkDesSize,1 
    jmp FoundDestination

    Check_BH:
    checkEQUALITY des,bh_str
    jnz Check_CL
    mov bx,offset BHREG
    mov checkDesSize,1 
    jmp FoundDestination

    Check_CL:
    checkEQUALITY des,cl_str
    jnz Check_CH
    mov bx,offset CLREG
    mov checkDesSize,1 
    jmp FoundDestination

    Check_CH:
    checkEQUALITY des,ch_str
    jnz Check_DL
    mov bx,offset CHREG
    mov checkDesSize,1 
    jmp FoundDestination

    Check_DL:
    checkEQUALITY des,dl_str
    jnz Check_DH
    mov bx,offset DLREG
    mov checkDesSize,1 
    jmp FoundDestination

    Check_DH:
    checkEQUALITY des,dh_str
    jnz FoundDestination
    mov bx,offset DHREG
    mov checkDesSize,1 
    jmp FoundDestination

    FoundDestination:
endm CheckDestination 

;-----------DETECT DIRECT DESTINATION---------
DirectDestination macro des
    local harf
    local Dexite
    mov bx,offset memory
    mov dh,0
    mov dl,des
    sub dl,30h
    cmp dl,9
    ja harf
    add bx,dx
    jmp Dexite
    harf:
    sub dl,7
    add bx,dx
    Dexite: 
    mov checkDesSize,0
endm DirectDestination
;-----------DETECT INDIRECT DESTINATION---------    
RegIndirect macro des
    CheckDestination des
    mov ax,[bx]
    mov bx,offset memory
    add bx,ax
    mov checkDesSize,0    
endm RegIndirect

BasedRelativeDES macro des
    CheckDestination des
    mov ax,[bx]
    DirectDestination des+3
    add bx,ax
    mov checkDesSize,0    
endm BasedRelativeDES