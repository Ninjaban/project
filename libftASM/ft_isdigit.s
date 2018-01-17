global	_ft_isdigit

section .text

_ft_isdigit:
	cmp rdi, 48
	jl no
	cmp rdi, 57
	jg no
	jmp yes

yes:
	mov rax, 1
	jmp end

no:
	mov rax, 0
	jmp end

end:
	ret