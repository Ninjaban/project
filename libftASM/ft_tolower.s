global	_ft_tolower

section	.text

_ft_tolower:
	mov rax, rdi
	cmp rdi, 65
	jl end
	cmp rdi, 90
	jle lower
	cmp rdi, 90
	jg end

lower:
	add rax, 32
	jmp end

end:
	ret