/*************************************************************************
	> File Name: testSimpleSection.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Fri 16 Oct 2015 03:34:41 PM CST
 ************************************************************************/

#include<stdio.h>

int global_init_var = 84;
int global_uninit_var;

void func( int i ){
	printf("%d\n", i);
}

int main()
{
	static int static_var = 85;
	static int static_var2;
	
	int a = 1;
	int b;

	func(static_var + static_var2 + a + b);
    return 0;
}
