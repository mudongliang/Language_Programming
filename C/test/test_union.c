/*************************************************************************
	> File Name: union.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Fri 10 Jul 2015 10:00:44 AM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

union test{
	long l1;
	char * p2;
}a;
int main(int argc,const char *argv[])
{
	a.p2 = (char *)malloc(sizeof(a));
	free(a.p2);
	char * b = a.l1; 
	a.p2 = NULL;
	printf("a.l1 = %ld\n",a.l1);
    return 0;
}
