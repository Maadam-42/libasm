	extern	___error
	global	_ft_read
	segment	.text
_ft_read:		
	mov		rax, 0x2000003
	syscall
	jc		.error
	ret
.error:
	call	___error
	mov		rax, -1
	ret
