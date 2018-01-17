global _ft_strcat
extern _ft_strlen

section .text

_ft_strcat :
	push rdi
	mov rax, 0
	mov rcx, -1
	repne scasb
	dec rdi
	push rdi
	mov rdi, rsi
	call _ft_strlen
	mov rcx, rax
	pop rdi
	rep movsb
	mov rdi, 0
	pop rdi
	mov rax, rdi
	ret