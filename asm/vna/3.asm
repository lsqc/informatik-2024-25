section .data
    x dq 12
    y dq 7
    min dq 0
    diff dq 0

section .text
    global _start

_start:
    mov rax, [x]
    mov rbx, [y]

    cmp rax, rbx
    jl smaller_x
    mov [min], rbx
    jmp compute_diff

smaller_x:
    mov [min], rax

compute_diff:
    mov rax, [x]
    sub rax, [y]
    jns store_diff
    neg rax
store_diff:
    mov [diff], rax

    mov rax, 60
    xor rdi, rdi
    syscall
