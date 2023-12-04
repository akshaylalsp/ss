assume cs:code,ds:data
 data segment
  msg1 db 0ah,0dh,"enter no $"
  msg2 db 0ah,0dh,"factorial is $"
  num1 dw 0000h
 
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
        l1:
         mov ah,01h
         int 21h
         cmp al,0dh
         je l2
         mov ah,00h
         sub al,30h
         mov bx,ax
         mov dx,000ah
         pop ax
         mul dx
         add ax,bx
         push ax
         jmp l1
        l2:
         pop ax
         ret
        read endp    
     display proc
      push dx
      mov bx,000ah
      xor cx,cx
      l3:
       xor dx,dx
       div bx
       add dx,0030h
       push dx
       inc cx
       cmp ax,0000h
       jnz l3
      l4:
      pop dx
      mov ah,02h
      int 21h
      loop l4
      pop dx
      ret
   display endp  
   factorial proc
    mov ax,0001h
    mov cx,num1
        l5:  mul cx
        dec cx
        jnz l5
        call display
        ret
        factorial endp
 
       
     start:
     mov ax,data
     mov ds,ax
     print msg1
     call read
     mov num1,ax
   
     print msg2
     call factorial
     mov ah,4ch
     int 21h
  code ends
  end start