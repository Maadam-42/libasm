	global	_ft_strlen
	segment	.text
_ft_strlen:
	xor		rax, rax
.loop:
	cmp		byte[rdi + rax], 0
	jz		.done
	inc		rax
	jmp		.loop
.done:
	ret