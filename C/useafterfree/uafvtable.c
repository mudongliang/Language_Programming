/*************************************************************************
	> File Name: useafterfree.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 20 Apr 2015 08:51:00 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>

struct vtable {
	void * vptr;
	int vtguard;
};

int test(){
	printf("testing ...\n");
	return 0;
}

typedef int (*mFun)();

int main()
{
	char *a, *b;
	a = malloc(24);
	printf("a = %p\n",a);
	free(a);

	printf("sizeof struct vtable = %lu\n",sizeof(struct vtable));

	b = malloc(sizeof(struct vtable));
	printf("a = %p\n",b);
	((struct vtable *)a)->vptr = (void *)test;

	mFun m = (mFun)((struct vtable *)b)->vptr;
	m();
    return 0;
}
