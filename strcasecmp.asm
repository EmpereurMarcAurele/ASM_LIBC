section	.text

	global	strcasecmp

strcasecmp:
	
	xor	r8, r8
while:
	xor	rax, rax
	xor	rcx, rcx
	mov	al, BYTE [rdi + r8]
	cmp	al, 97
	jge	go_maj
next:	
	mov	cl, BYTE [rsi + r8]
	cmp	cl, 97
	jge	go_maj2
next2:	
	sub	rax, rcx
	cmp	BYTE [rdi + r8], 0
	je	final
	cmp	BYTE [rsi + r8], 0
	je	final
	cmp	rax, 0
	jne	final
	inc	r8
	jmp	while
go_maj:
	cmp	al, 123
	jge	next
	sub	al, 32
	jmp	next
go_maj2:
	cmp	cl, 123
	jge	next2
	sub	cl, 32
	jmp	next2
final:
	ret
