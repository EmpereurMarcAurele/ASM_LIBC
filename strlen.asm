section .text

	global	strlen

strlen:	
	xor rax, rax
while:
	cmp BYTE [rdi + rax], 0
	je end_while
	inc rax
	jmp while
end_while:
	ret
