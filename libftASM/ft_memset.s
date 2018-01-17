global	_ft_memset

section	.text

_ft_memset:
	push rdi
	cmp rdx, 0
	je end
	mov rax, rdi
	mov rbx, rsi
	mov rcx, rdx
	mov al, bl
	rep stosb 

end :
	pop rax
	ret