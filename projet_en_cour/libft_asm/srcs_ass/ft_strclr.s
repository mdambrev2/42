; void				ft_strclr(char *str);

section .text
	global _ft_strclr
	extern _ft_bzero
	extern _ft_strlen

_ft_strclr:
	cmp		rdi, 0
	je		.ret
	call 	_ft_strlen
	mov 	rsi ,rax
	call	_ft_bzero

.ret:
	ret
