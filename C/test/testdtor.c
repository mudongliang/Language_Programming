/*************************************************************************
	> File Name: testdtor.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Fri 23 Oct 2015 06:16:31 PM CST
 ************************************************************************/

#include<stdio.h>

static void goodbye(void) __attribute__ ((destructor));

int main(int argc,const char *argv[])
{
	printf("During the program, hello\n");
    return 0;
}

void goodbye(void){
	printf("After the program, bye\n");
}
