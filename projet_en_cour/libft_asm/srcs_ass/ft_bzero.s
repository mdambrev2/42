; void					ft_bzero(void *s, size_t n);

section .text
	global 	_ft_bzero
	extern 	_ft_memset

_ft_bzero:
	cmp 	rdi, 0
	jne 	.memset
	ret

.memset:
	mov 	rdx, rsi
	mov		rsi, 0
	call	_ft_memset
	ret
