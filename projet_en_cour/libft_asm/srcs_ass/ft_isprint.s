; int			ft_isprint(int c);

section .text
	global	_ft_isprint

_ft_isprint:
	mov		rax, 0
	cmp		rdi, 32
	jl		.ret
	cmp		rdi, 126
	jg		.ret
	add		rax, 1
.ret:
	ret
