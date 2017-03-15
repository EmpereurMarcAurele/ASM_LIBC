section	.text

	global	strncmp

strncmp:
	xor	r8, r8
while:
	xor	rax, rax
	xor	rcx, rcx
	mov	al, BYTE [rdi + r8]
	mov	cl, BYTE [rdi + r8]
	sub	rax, rcx
	cmp	BYTE [rdi + r8], 0
	je	final
	cmp	BYTE [rsi + r8], 0
	je	final
	cmp	rax, 0
	jne	final
	cmp	r8, rdx
	je	final	
	inc	r8
	jmp	while
final:
	ret
	
