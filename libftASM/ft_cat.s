global	_ft_cat

section	.text

_ft_cat:
	
.read:
	mov rax, 0x2000003
	push rdi
	lea rsi, [rel buff_size]
	mov rdx, buffsize
	syscall
	jc end
	cmp rax, 0
	je end
	mov rax, 0x2000004
	mov rdi, 1
	mov rdx, buffsize
	syscall
	pop rdi
	jmp .read

end:
	pop rdi
	ret


section	.data
	buff_size db 100
	buffsize equ $ - buff_size