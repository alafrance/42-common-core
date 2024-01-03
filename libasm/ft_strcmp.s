global _ft_strcmp

section .text
_ft_strcmp:
    xor rax, rax
    xor rcx, rcx
while:
    movzx r8, BYTE [rdi + rcx]
    movzx r9, BYTE [rsi + rcx]
    mov r10, r8
    or r8, r9
    jz end
    sub r10, r9
    jl inf
    jg sup
    inc rcx
    jmp while
end:
    ret
sup:
    mov rax, 1
    ret

inf:
    mov rax, -1
    ret