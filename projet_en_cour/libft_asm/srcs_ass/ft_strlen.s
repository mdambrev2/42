; int 				ft_strlen.s(char *str);

section .text
	global _ft_strlen

_ft_strlen:
	mov rax, 0
	cmp rdi, 0
	push rdi
	je 		.ret
	mov     al , 0         
	mov     rcx , -1
	repne	scasb        
	mov		rax, rcx
	add		rax, 2
	mov		rbx, -1
	mul		rbx

.ret:
	pop rdi
	ret
