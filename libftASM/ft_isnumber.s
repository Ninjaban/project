global	_ft_isnumber

section	.text

_ft_isnumber:
	cmp rdi, 48
	jl no
	cmp rdi, 57
	jle yes
	cmp rdi, 65
	jl no
	cmp rdi, 90
	jle yes
	cmp rdi, 97
	jl no
	cmp rdi, 122
	jle yes
	cmp rdi, 122
	jg no

yes:
	mov rax, 1
	jmp end

no:
	mov rax, 0
	jmp end

end:
	ret