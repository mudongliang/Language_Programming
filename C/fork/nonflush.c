/*************************************************************************
	> File Name: flush.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Fri 22 May 2015 05:10:22 PM HKT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main(int argc,const char *argv[])
{
	printf("one");
	fork();
	printf("two\n");
    return 0;
}
