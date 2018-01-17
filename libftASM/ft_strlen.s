global	_ft_strlen

section .text

_ft_strlen :
	push rdi
	push rcx
	sub rax, rax
	sub rcx, rcx
	not rcx
	dec rcx
	repne scasb
	inc rcx
	not rcx
	dec rcx
	mov rax, rcx

end :
	pop rcx
	pop rdi
	ret