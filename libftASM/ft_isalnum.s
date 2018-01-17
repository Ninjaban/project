global _ft_isalnum

section .text
	
_ft_isalnum :
	cmp	rdi, 58
	jnge num
	cmp rdi, 65
	jnl alpha
	jmp no

num :
	cmp rdi, 47
	jnle yes
	cmp rdi, 47
	jng no

alpha :
	cmp rdi, 123
	jge no
	cmp	rdi, 91
	jnge yes
	cmp rdi, 97
	jnge no

yes :
	mov rax, 1
	jmp end

no :
	mov rax, 0
	jmp end

end :
	ret