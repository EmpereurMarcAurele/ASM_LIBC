section	.text

	global	memset

memset:
	mov	rax, rdi
	xor	r8, r8
while:
	cmp	r8, rdx
	je	end_while
	mov	[rdi + r8], rsi
	inc	r8
	jmp	while
end_while:
	ret
	
