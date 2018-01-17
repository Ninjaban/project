global	_ft_bzero

section	.text

_ft_bzero:
	mov rax, rsi	; met size_t n dans rax
	mov rbx, rdi	; met void *s dans rbx
	jmp while	; rejoindre la boucle

while:
	cmp rax, 0	; verifier si s[n] = 0
	jz end		; si oui, on sort de la boucle et on va a end
	mov byte[rbx], 0; sinon, on met *s = 0
	dec rax		; decrementation de n
	inc rbx		; incrementation de s
	jmp while	; rappel de la boucle

end:
	ret		; fin du programme et affiche $