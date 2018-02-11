/*************************************************************************
	> File Name: useafterfree.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 20 Apr 2015 08:51:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

#define NUM 25 //24
int main(int argc,const char *argv[])
{
	char *a, *b, *c;
	a = malloc(NUM);
	b = malloc(NUM);
	c = malloc(NUM);

	printf("a = %p\n",a);
	printf("b = %p\n",b);
	printf("c = %p\n",c);
	free(a);
	free(b);
	free(c);
	return 0;
}
