assume cs:code,ds:data
data segment
    msg1 db "enter no $"
    msg2 db 0ah,0dh, "sum is"
data ends

code segment
    start:
          mov ax,data
          mov ds,ax

          lea dx,msg1

          mov ah,09h
          int 21h
          mov ah,4ch
          int 21h

code ends
end start



