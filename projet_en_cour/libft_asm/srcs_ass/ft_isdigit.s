; int			ft_isdigit.s(int c);

section .text
	global	_ft_isdigit

_ft_isdigit:
	mov		rax, 0
	cmp		rdi, 48
	jl		.ret
	cmp		rdi, 58
	jge		.ret
	add		rax, 1
.ret:
	ret
