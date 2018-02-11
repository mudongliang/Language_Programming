/*************************************************************************
	> File Name: useafterfree.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 20 Apr 2015 08:51:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *a;
	a = malloc(0x10);
	//printf("a = %p\n",a);
	free(a);
	a = NULL;
	return 0;
}
