section .data
    x dq 5
    z dq 10
    result dq 0

section .text
    global _start

_start:
    mov rax, [x]
    add rax, [z]
    mov [result], rax

    mov rax, 60
    xor rdi, rdi
    syscall