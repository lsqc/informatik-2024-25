section .data
    secret dq 69
    guess dq 0
    message db "erraten", 0xA
    msg_len equ $-message

section .bss
    input resb 4

section .text
    global _start

_start:
    mov rax, 0
    mov rdi, 0
    mov rsi, input
    mov rdx, 4
    syscall

    movzx rax, byte [input]
    sub rax, '0'
    imul rax, 10
    movzx rbx, byte [input+1]
    sub rbx, '0'
    add rax, rbx

    mov [guess], rax
    mov rax, [guess]
    cmp rax, [secret]
    jne wrong_guess

    mov rax, 1
    mov rdi, 1
    mov rsi, message
    mov rdx, msg_len
    syscall

    mov rax, 60
    xor rdi, rdi
    syscall

wrong_guess:
    mov rax, 60
    xor rdi, rdi
    syscall
