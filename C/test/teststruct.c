/*************************************************************************
	> File Name: teststruct.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: 2015年09月23日 星期三 20时32分33秒
 ************************************************************************/

#include<stdio.h>

struct A{
	char a;
	int b;
};

int main(int argc,const char *argv[])
{
	struct A test;
	test.a = 'c';
	test.b = 12;
	printf("size = %d\n", sizeof(struct A));
	printf("a = %c and b = %d\n", test.a, test.b);
    return 0;
}
