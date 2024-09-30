section .data
    x dq 10
    z dq 3
    y dq 1
    w dq 0

section .text
    global _start

_start:
    mov rax, [y]
    cmp rax, 1
    je add_numbers
    cmp rax, 2
    je sub_numbers
    jmp exit

add_numbers:
    mov rax, [x]
    add rax, [z]
    mov [w], rax
    jmp exit

sub_numbers:
    mov rax, [x]
    sub rax, [z]
    mov [w], rax
    jmp exit

exit:
    mov rax, 60
    xor rdi, rdi
    syscall
