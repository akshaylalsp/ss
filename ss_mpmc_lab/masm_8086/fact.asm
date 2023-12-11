assume cs:code,ds:data 
data segment
    msg1 db,"enter no : $"
    msg2 db,"result is : $"
    num1 dw,0000h
    num2 dw,0000h
data ends

code segment
    print macro msg
        lea dx,msg
        mov ah,09h
        int 21h
    endm

    read proc
    
        xor ax,ax
        push ax
        mov dx,0000h

        l1: mov ah,01h
            int 21h
            cmp al,000Dh
            je l2
            mov ah,00h
            sub al,30h
            mov bx,ax
            pop ax
            mul dx
            add ax,bx
            push ax
            jmp l1
        l2: pop ax
            ret 


    read endp

    display proc
        mov bx,000ah
        mov cx,0000h
        l3: xor dx,dx
            div bx
            add dx,0030h
            push dx
            inc cx
            cmp ax,0000h
            jnz l3

        l4: pop dx
            mov ah,02h
            int 21h
            loop l4
            ret


    display endp

    factn proc
    print msg2      ; Print the "result is:" message
    mov cx, num1    ; Load the input number (factorial)
    mov ax, 1       ; Initialize result to 1

    cmp cx, 0       ; Check if the input is 0
    je  l6           ; If yes, skip the loop

    l5: mul cx       ; Multiply result by cx
        dec cx       ; Decrement cx
        jnz l5       ; Continue loop if cx is not zero

    l6: call display ; Display the result
    ret
    factn endp


    start:  
            mov ax,data
            mov ds,ax
            print msg1
            call read
            mov num1,ax
            print msg1
            call read
            mov num2,ax
            call factn
            mov ah,4ch
            int 21h
code ends
end start
