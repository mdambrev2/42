; int ft_puts(const char *s)

section .data
	null 	db "(null)"

section .text
	global _ft_puts
	extern _ft_strlen

_ft_puts:
	push 	rcx
	push	rdx
	push	rdi
	push	rsi
	cmp 	rdi, 0
	je		.null
	jmp		.write

.write:	
	call 	_ft_strlen
	mov 	rcx, rdi
	mov 	rdi, 1
	mov		rdx, rax
	mov 	rsi, rcx
	mov 	rax, 0x2000004
	syscall
	mov		rax, 42
	jmp 	.chariot

.toto:
	db 10

.chariot:
	mov 	rax, 0x2000004
	mov  	rdi, 1
	mov	 	rdx, 1
	lea		rsi, [rel .toto]
	syscall
	jmp 	.ret

.null:
	mov 	rax, 0x2000004
	mov  	rdi, 1
	mov	 	rdx, 6
	lea	 	rsi, [rel null]
	syscall
	mov		rax, -1
	jmp 	.chariot

.ret:
	pop rsi
	pop rdi
	pop	rdx
	pop	rcx
	ret
