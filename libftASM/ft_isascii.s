global	_ft_isascii

section .text

_ft_isascii:
	cmp rdi, 127
	jle yes
	jmp no

yes:
	mov rax, 1
	jmp end

no:
	mov rax, 0
	jmp end

end:
	ret