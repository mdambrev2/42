section .data
hello:
	.string db "section .data%1$chello:%1$c%2$c.string db %3$c%4$s%3$c%1$c%1$csection .text%1$c%2$cglobal start; com1%1$c%2$cglobal _main; com2%1$c%2$cextern _printf%1$c%1$cstart:%1$c%2$ccall _main%1$c%2$cret%1$c%1$c_main:%1$c%2$cpush rbp%1$c%2$cmov rbp, rsp%1$c%2$csub rsp, 16%1$c%2$clea rdi, [rel hello.string]%1$c%2$cmov rsi, 10%1$c%2$cmov rdx, 9%1$c%2$cmov rcx, 34%1$c%2$clea r8, [rel hello.string]%1$c%2$ccall _printf%1$c%2$cleave%1$c%2$cret%1$c"

section .text
	global start; com1
	global _main; com2
	extern _printf

start:
	call _main
	ret

_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel hello.string]
	mov rsi, 10
	mov rdx, 9
	mov rcx, 34
	lea r8, [rel hello.string]
	call _printf
	leave
	ret
