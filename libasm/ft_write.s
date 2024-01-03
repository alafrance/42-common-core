extern			___error	
global			_ft_write
section			.text
_ft_write:
	mov			rax, 0x02000004
	syscall
	jc 			error
	ret
error:
	mov rdi, rax
	call ___error
	mov [rax], rdi
	mov rax, -1
	ret