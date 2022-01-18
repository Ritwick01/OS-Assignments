section .bss
   storage resb 8 

section .data
   text_new db "Presently in Function B", 10

section .text          ;Code Segment
   global funcB
   extern hello

funcB:
   mov [storage], rdi
   mov rax, 1
   mov rdi, 1
   mov rsi, text_new
   mov rdx, 25
   syscall
   mov rax, 1
   mov rdi, 1
   mov rsi, storage
   mov rdx, 8
   syscall
   push hello
   ret

   
