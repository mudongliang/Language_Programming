/*************************************************************************
	> File Name: getsp.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Sat 13 Jun 2015 04:35:11 PM CST
 ************************************************************************/

#include<stdio.h>

unsigned long sp(void){
#if defined(__i386__)
	asm("mov %esp, %eax");
#elif defined(__x86_64__)
	asm("mov %rsp, %rax");
#endif
}
int main(int argc,const char *argv[])
{
	unsigned long esp = sp();  
	printf("Stack pointer (ESP : 0x%lx)\n",esp);
    return 0;
}
