section .data
    x dq 10
    y dq 0
    z dq 0
    divisor dq 5

section .text
    global _start

_start:
    mov rax, [x]
    test rax, 1
    jnz odd_number
    mov qword [y], 1
    jmp check_divisor

odd_number:
    mov qword [y], 0

check_divisor:
    mov rax, [x]
    xor rdx, rdx
    div qword [divisor]
    test rdx, rdx
    jnz not_divisible
    mov qword [z], 1
    jmp exit

not_divisible:
    mov qword [z], 0

exit:
    mov rax, 60
    xor rdi, rdi
    syscall
