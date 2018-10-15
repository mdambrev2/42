section .data

hello:
.string db "section .data%1$c%1$chello:%1$c.string db %2$c%3$s%2$c, 10, 0%1$c%1$coption:%1$c.string db %2$cw+%2$c, 0%1$c%1$cfile_name:%1$c.string db %2$c./Sully_%%1$d.s%2$c, 0%1$cexec_nasm:%1$c.string db %2$c~/.brew/bin/nasm -f macho64 Sully_%%1$d.s%2$c, 0%1$c%1$cexec_gcc:%1$c.string db %2$cgcc -Wall -Werror -Wall -g Sully_%%1$d.o -o Sully_%%1$d%2$c%1$c%1$csection .text%1$cglobal start%1$cglobal _main%1$cextern _fprintf%1$cextern _fopen%1$cextern _printf%1$cextern _sprintf%1$cextern _malloc%1$cextern _system%1$c%1$cstart:%1$ccall _main%1$cret%1$c%1$c%%macro get_file_name 0%1$c%1$cmov rdi, 42%1$ccall _malloc%1$cmov r13, rax%1$cmov r13, rax%1$cmov rdi, rax%1$clea rsi, [rel file_name.string]%1$cdec r14%1$cmov rdx, r14%1$ccall _sprintf%1$cmov rdi, r13%1$c%1$c%%endmacro%1$c%1$c%%macro fopen 0%1$c%1$clea rsi, [rel option.string]%1$ccall _fopen%1$c%1$c%%endmacro%1$c%1$c%%macro printf 0%1$c%1$cmov rdi, rax%1$clea rsi, [rel hello.string]%1$cmov rdx, 10%1$cmov rcx, 34%1$cmov r8, [rel hello.string]%1$cmov r9, r14%1$ccall _fprintf%1$c%1$c%%endmacro%1$c%1$c%%macro exec_nasm 0%1$c%1$cmov rdi, 42%1$ccall _malloc%1$cmov r13, rax%1$cmov rdi, rax%1$clea rsi, [rel exec_nasm.string]%1$cmov rdx, r14%1$ccall _sprintf%1$cmov rdi, r13%1$ccall _system%1$c%1$c%%endmacro%1$c%1$c%%macro exec_gcc 0%1$c%1$cmov rdi, 42%1$ccall _malloc%1$cmov r13, rax%1$cmov rdi, rax%1$clea rsi, [rel exec_gcc.string]%1$cmov rdx, r14%1$cmov rcx, 59%1$ccall _sprintf%1$cmov rdi, r13%1$ccall _system%1$c%1$c%%endmacro%1$c%1$c_main:%1$cpush rbp%1$cmov rbp, rsp%1$csub rsp, 16%1$cmov r14, 5%1$cCMP r14, 0%1$cJNG ret%1$cget_file_name%1$cfopen%1$cprintf%1$cexec_nasm%1$cexec_gcc%1$c%1$cret:%1$cleave%1$cret", 10, 0

option:
.string db "w+", 0

file_name:
.string db "./Sully_%1$d.s", 0
exec_nasm:
.string db "~/.brew/bin/nasm -f macho64 Sully_%1$d.s", 0

exec_gcc:
.string db "gcc -Wall -Werror -Wall -g Sully_%1$d.o -o Sully_%1$d"

section .text
global start
global _main
extern _fprintf
extern _fopen
extern _printf
extern _sprintf
extern _malloc
extern _system

start:
call _main
ret

%macro get_file_name 0

mov rdi, 42
call _malloc
mov r13, rax
mov r13, rax
mov rdi, rax
lea rsi, [rel file_name.string]
dec r14
mov rdx, r14
call _sprintf
mov rdi, r13

%endmacro

%macro fopen 0

lea rsi, [rel option.string]
call _fopen

%endmacro

%macro printf 0

mov rdi, rax
lea rsi, [rel hello.string]
mov rdx, 10
mov rcx, 34
mov r8, [rel hello.string]
mov r9, r14
call _fprintf

%endmacro

%macro exec_nasm 0

mov rdi, 42
call _malloc
mov r13, rax
mov rdi, rax
lea rsi, [rel exec_nasm.string]
mov rdx, r14
call _sprintf
mov rdi, r13
call _system

%endmacro

%macro exec_gcc 0

mov rdi, 42
call _malloc
mov r13, rax
mov rdi, rax
lea rsi, [rel exec_gcc.string]
mov rdx, r14
mov rcx, 59
call _sprintf
mov rdi, r13
call _system

%endmacro

_main:
push rbp
mov rbp, rsp
sub rsp, 16
mov r14, 5
CMP r14, 0
JNG ret
get_file_name
fopen
printf
exec_nasm
exec_gcc

ret:
leave
ret