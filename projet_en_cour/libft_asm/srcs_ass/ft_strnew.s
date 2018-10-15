; void				ft_strnew(size_t size)

section .text
	global _ft_strnew
	extern _malloc
	extern _bzero

_ft_strnew:
	push	rdi
	call 	_malloc
	cmp		rax, 0
	je		.ret

	pop		rdi
	push	rax
	mov		rsi, rdi
	mov 	rdi, rax
	call	_bzero
	pop		rax

.ret:
	ret
