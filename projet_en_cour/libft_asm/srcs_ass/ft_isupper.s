; int 			ft_isupper(int c);

section .text
	global _ft_isupper

_ft_isupper:
	mov		rax, 0
	cmp		rdi, 65
	jl		.ret
	cmp		rdi, 90
	jg		.ret
	add		rax, 1
	
.ret:
	ret	
