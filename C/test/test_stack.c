/*************************************************************************
	> File Name: test_stack.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: 2015年05月16日 星期六 20时21分55秒
 ************************************************************************/

#include<stdio.h>

void b(int argc) {
	printf("b argc = %d\n", argc);
}

void a(int argc){
	b(argc+1);
	printf("a argc = %d\n", argc);
}

int main(int argc,const char *argv[])
{
	a(argc);	
    return 0;
}
