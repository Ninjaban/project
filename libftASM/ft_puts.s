global	_ft_puts

section .text

_ft_puts:
	mov rax, rdi
	mov rcx, rdi
	cmp rdi, 0
	jz null
	mov r8, 0
	jmp len

null:
	mov rdi, 1
	lea rsi, [rel null_msg]
	mov rdx, 7
	mov rax, 0x2000004
	syscall
	ret

len:
	cmp byte[rax], 0
	jz wri
	inc r8
	inc rax
	jmp len

wri:
	mov rax, 0x2000004
	mov rdi, 1
	mov rsi, rcx
	mov rdx, r8
	syscall
	mov rdi, 1
	mov rdx, 1
	mov rax, 0x2000004
	lea rsi, [rel new_line]
	syscall
	ret

section .data
	new_line db 10
	null_msg db "(null)", 10