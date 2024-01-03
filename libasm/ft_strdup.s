extern _malloc
extern _ft_strlen
extern _ft_strcpy
global  _ft_strdup

section .text

_ft_strdup:
    call _ft_strlen
    push rdi
    add rax, 1
    mov rdi, rax
    call _malloc
    pop rdx
    mov rdi, rax
    mov rsi, rdx
    call _ft_strcpy
    ret