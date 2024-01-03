extern	___error
global	_ft_read
section	.text
_ft_read:
	mov	rax, 0x02000003
	syscall
	jc	error
	ret

error:
	mov rdi, rax
	call ___error
	mov [rax], rdi
	mov rax, -1
	ret