global		_ft_strcpy
section		.text

_ft_strcpy:
	xor	rcx, rcx
while:
    mov  r8b, [rsi + rcx]       
    mov  r9b, [rdi + rcx]       
	mov  [rdi + rcx], r8b
	or	r8b, r8b
    je end
	inc	rcx
    jmp while
end:
    mov rax, rdi
    ret