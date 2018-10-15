%macro STR 0
section .data
hello:
	.string db "%%macro STR 0%1$csection .data%1$chello:%1$c%2$c.string db %3$c%4$s%3$c, 0%1$coption:%1$c%2$c.string db %3$cw+%3$c, 0%1$cfile_name:%1$c%2$c.string db %3$cGrace_kid.s%3$c, 0%1$c%%endmacro%1$c%1$c%%macro START 0%1$csection .text%1$c%2$cglobal start%1$c%2$cglobal _main%1$c%2$cextern _fprintf%1$c%2$cextern _fopen%1$cstart:%1$c%2$ccall _main%1$c%2$cret%1$c%%endmacro%1$c%1$c%%macro MAIN 0%1$c_main:%1$c%2$cpush rbp%1$c%2$cmov rbp, rsp%1$c%2$csub rsp, 16%1$c%2$clea rdi, [rel file_name.string]%1$c%2$clea rsi, [rel option.string]%1$c%2$ccall _fopen%1$c%2$cmov rdi, rax%1$c%2$clea rsi, [rel hello.string]%1$c%2$cmov rdx, 10%1$c%2$cmov rcx, 9%1$c%2$cmov r8, 34%1$c%2$clea r9, [rel hello.string]%1$c%2$ccall _fprintf%1$c%2$cleave%1$c%2$cret%1$c%%endmacro%1$c%1$cSTR%1$cSTART%1$cMAIN%1$c", 0
option:
	.string db "w+", 0
file_name:
	.string db "Grace_kid.s", 0
%endmacro

%macro START 0
section .text
	global start
	global _main
	extern _fprintf
	extern _fopen
start:
	call _main
	ret
%endmacro

%macro MAIN 0
_main:
	push rbp
	mov rbp, rsp
	sub rsp, 16
	lea rdi, [rel file_name.string]
	lea rsi, [rel option.string]
	call _fopen
	mov rdi, rax
	lea rsi, [rel hello.string]
	mov rdx, 10
	mov rcx, 9
	mov r8, 34
	lea r9, [rel hello.string]
	call _fprintf
	leave
	ret
%endmacro

STR
START
MAIN
