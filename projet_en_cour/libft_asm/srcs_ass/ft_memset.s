; void			*ft_memset(void *s, int c, size_t n);

section .text
	global _ft_memset

_ft_memset:
	
	cmp 	rdi, 0
	je		.ret
	
	cmp 	rdx, 0
	je 		.ret
	

	push	rdi
	mov 	rcx, rdx
	mov		al, sil
	rep 	stosb
	pop 	rax
	

.ret:
	ret

