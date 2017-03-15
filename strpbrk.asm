section	.text

	global	strpbrk

strpbrk:
	xor	rax, rax
	xor	r8, r8
while:
	cmp	r8, rdi
	je	final
	cmp	r8, rsi
	je	final
	mov	r9b, BYTE [rdi + r8]
	mov	r10b, BYTE [rsi + r8]
	cmp	r9b, r10b
	je	final
	inc	r8
	jmp	while
final:
	ret
