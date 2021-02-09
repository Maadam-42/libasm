	extern	___error
	global	_ft_write
	segment	.text
_ft_write:		
	mov		rax, 0x2000004
	syscall
	jc		.error
	ret		
.error:
	call	___error
	mov		rax, -1
	ret