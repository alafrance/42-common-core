section .text
global _ft_strlen

_ft_strlen:
    xor rax, rax
while:
        mov r8b, [rdi + rax]
        or r8b, r8b
        je end
        inc rax
        jmp while
end:
    ret
