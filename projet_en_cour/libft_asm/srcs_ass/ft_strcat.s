; char 				*ft_strcat.s(char *dest, const char *src);

section .text
	global _ft_strcat

_ft_strcat:
	mov rax, rdi
	jmp .incrdi

.ret:
	mov [rdi], byte 0
	mov rdi, rax
	ret

.incrdi:
	cmp [rdi], byte 0
	je 	 .cpyrsi
	inc rdi
	jmp .incrdi

.cpyrsi:
	cmp [rsi], byte 0
	je 	.ret
	mov cl, [rsi]
	mov [rdi], cl
	inc rsi
	inc rdi
	jmp .cpyrsi
