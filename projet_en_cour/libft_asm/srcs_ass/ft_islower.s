; int 			ft_islower(int c);

section .text
	global	_ft_islower

_ft_islower:
	mov		rax, 0
	cmp		rdi, 97
	jl		.ret
	cmp		rdi, 122
	jg		.ret
	add 	rax, 1

.ret:
	ret
