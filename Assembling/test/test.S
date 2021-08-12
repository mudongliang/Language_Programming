/* test.S
 * $ as -o test.o test.S
 * $ ld -o test test.o
 */

.data
msg:    .ascii  "Hello, world!\n"

.text
    
.global _start

_start:
        mov    $1,%rax
        mov    $1,%rdi
        mov    $msg,%rsi
        mov    $14,%rdx
        syscall

        mov    $60,%rax
        mov    $0,%rdi
        syscall
