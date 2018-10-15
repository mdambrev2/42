; int 			ft_cat.s(int fd);


section .data
	buffer db 1

section .text
	global _ft_cat

_ft_cat:
	push 	rdi
	mov		rdx, 1
	jmp		.boucle

.boucle:
	
	mov 	rax, 0x2000003
	lea		rsi, [rel buffer]
	mov		rdx, 1
	syscall
	jc		.ret
	cmp 	rax, 0
	je		.ret
	push	rdi
	mov		rax, 0x2000004
	mov		rdi, 1
	lea		rsi, [rel buffer]
	mov		rdx, 1
	syscall
	pop 	rdi
	jmp 	.boucle


.ret:
	pop rdi
	mov rax, 0
	ret
