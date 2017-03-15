section	.text

	global	strstr

strstr:
	xor	r8, r8
	xor	rax, rax

while:
	cmp	BYTE [rdi + r8], 0
	je	final
	cmp	BYTE [rdi + r8], sil
	je	good_str
	
final:
	ret
	
good_str:
	inc	r8
	xor	rax, rax
	xor	rcx, rcx
	mov	al, BYTE [rdi + r8]
	mov	cl, BYTE [rsi + r8]
	cmp	al, cl
	
