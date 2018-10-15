; void 				*ft_memcpy.s(void *dest, const void *src, size_t n);

section .text
	global _ft_memcpy

_ft_memcpy:
	push	rdi
	push	rsi
	push	rdx
	mov 	rax, rdi
	mov		rcx, rdx
	rep		movsb

.ret:
	pop rdi
	pop	rsi
	pop rdx
	ret
