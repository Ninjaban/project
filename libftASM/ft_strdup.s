global	_ft_strdup

section	.text
	extern _malloc
	extern _ft_strlen
	extern _ft_memcpy

_ft_strdup:
	mov r14, 0
	mov r15, rdi
	call _ft_strlen
	inc rax
	mov r14, rax
	mov rdi, rax
	call _malloc
	mov rdx, r14
	mov [rax + r14], byte 0
	mov rdi, rax
	mov rsi, r15
	call _ft_memcpy
	ret