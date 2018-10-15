; int			ft_isalpha.s(int c);

section .text
	global	_ft_isalpha

_ft_isalpha:
	mov		rax, 1
	cmp		rdi, 65
	jl		.false
	cmp		rdi, 90
	jle		.ret
	cmp		rdi, 97
	jl		.false
	cmp		rdi, 122
	jle		.ret
	cmp		rdi, 123
	jge		.false

.ret:
	ret

.false:
	mov		rax, 0
	ret
