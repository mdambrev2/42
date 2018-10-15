; char 				*ft_strdup(const char *s1);

section .text
	global 	_ft_strdup
	extern	_ft_strlen
	extern	_malloc

_ft_strdup:
	call 	_ft_strlen
	push 	rdi
	add 	rax, 1
	mov 	rcx, rdi
	mov 	rdi, rax
	call 	_malloc

	pop		rdi
	push	rax
	call 	_ft_strlen
	add		rax, 1
	mov		rcx, rax
	pop		rax

	push	rdi
	mov		rsi, rdi
	mov		rdi, rax
	rep 	movsb
	pop		rdi


.ret:
	ret
