/*************************************************************************
	> File Name: sbrk.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 23 Nov 2015 03:51:48 PM CST
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{
	void *curr_brk, *tmp_brk = NULL;
	printf("Welcome to sbrk example : %d\n", getpid());
	tmp_brk = curr_brk = sbrk(0);
	printf("Program Break Location1: %p\n", curr_brk);
	getchar();

	brk(curr_brk+0x1000);

	curr_brk = sbrk(0);
	printf("Program break Location2: %p\n", curr_brk);
	getchar();

	brk(tmp_brk);

	curr_brk = sbrk(0);
	printf("Program break Location3: %p\n", curr_brk);
	getchar();
		
    return 0;
}
