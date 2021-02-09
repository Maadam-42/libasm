	global	_ft_strcmp
	segment	.text
_ft_strcmp:
	xor		rax, rax
	xor		rdx, rdx
.loop:
	mov		al, byte[rdi]
	mov		dl, byte[rsi]
	cmp		al, dl
	jne		.done
	test	al, al
	jz		.done
	inc		rdi
	inc		rsi
	jmp		.loop
.done:
	sub		rax, rdx
	ret