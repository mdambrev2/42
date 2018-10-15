; int			ft_isascii.s(int c);

section .text
	global	_ft_isascii

_ft_isascii:
	mov		rax, 0
	cmp		rdi, 0
	jl		.ret
	cmp		rdi, 127
	jg		.ret
	add		rax, 1
.ret:
	ret
