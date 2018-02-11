/*************************************************************************
	> File Name: useafterfree.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 20 Apr 2015 08:51:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

char * retptr(){
	char p, *q;
	q = &p;
	return q;
}

int main()
{
	char *a, *b, *c;
	a = malloc(16);
	printf("a = %p\n",a);
	b = a+5;
	free(a);
	b[2] = 'c';

	c = malloc(32);		//if parameter is greater than 16
	printf("c = %p\n",c);
	printf("c[7] = %c\n",c[7]);
	free(c);

	b = retptr();
	*b = 'c';
    return 0;
}
