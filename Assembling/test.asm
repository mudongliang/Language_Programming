
; test.asm
; $ nasm -f elf64 -o test.o test.asm
; $ ld -o test test.o

section .data
	msg	db "hello, world!",`\n`
section .text
	global	_start
_start:
	mov	rax, 1
	mov	rdi, 1
	mov	rsi, msg
	mov	rdx, 14
	syscall
	mov	rax, 60
	mov	rdi, 0
	syscall
