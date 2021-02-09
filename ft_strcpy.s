	global	_ft_strcpy
	segment	.text
_ft_strcpy:

	mov		rax, rdi
	xor		rcx, rcx
.loop:
	mov		dl, byte[rsi + rcx]
	mov		byte[rdi + rcx], dl
	test	dl, dl
	jz		.done
	inc		rcx
	jmp		.loop
.done:
	ret