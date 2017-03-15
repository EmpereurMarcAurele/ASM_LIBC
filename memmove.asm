section	.text

	global	memmove

memmove:
	xor	r8, r8
	mov	rax, rdi
while:
	cmp	r8, rdx
	je	end_while
	mov	r9b, BYTE [rsi + r8]
	mov	BYTE [rdi + r8], r9b
	inc	r8
	jmp	while
end_while:
	ret
