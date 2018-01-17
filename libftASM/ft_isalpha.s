global	_ft_isalpha

section .text

_ft_isalpha:
	cmp rdi, 65
	jnge no	
	cmp rdi, 91
	jnge yes
	cmp rdi, 97
	jnge no
	cmp rdi, 123
	jge no


yes:
	mov rax, 1
	jmp end

no:
	mov rax, 0
	jmp end

end:
	ret