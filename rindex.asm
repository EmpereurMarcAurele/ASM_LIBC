section	.text

	global	rindex

rindex:
	xor	r8, r8
	xor	rax, rax

while:
	cmp	r8, rdi
	je	final
	cmp	BYTE [rdi + r8], sil
	je	stock
	inc	r8
	jmp	while

stock:
	mov	al, BYTE [rdi + r8]
	jmp	while
final:
	ret
