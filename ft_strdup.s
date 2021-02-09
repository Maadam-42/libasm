	extern	___error
	extern	_malloc
	extern	_ft_strlen
	extern	_ft_strcpy
	global	_ft_strdup
	segment	.text
_ft_strdup:
	push	rdi
	call	_ft_strlen
	inc		rax
	mov		rdi, rax
	call	_malloc
	jc		.error
	mov		rdi, rax
	pop		rsi
	call	_ft_strcpy
	ret	
.error:
	call	___error
	mov		rax, -1
	ret
