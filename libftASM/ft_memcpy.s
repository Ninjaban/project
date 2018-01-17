global	_ft_memcpy

section	.text

_ft_memcpy:
	push rdi
	mov rcx, rdx
	cld
	repnz movsb
	jmp end

end:
	pop rax
	ret