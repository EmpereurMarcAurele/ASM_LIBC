section	.text

	global	strchr
	
strchr:
	xor	r8, r8
while:
	cmp	BYTE [rdi], sil
	je	find_occ
	cmp	BYTE [rdi], 0
	je	end_str
	inc	rdi
	jmp	while
end_str:
	xor	rax, rax
	ret
find_occ:
	mov	rax, rdi
	ret
