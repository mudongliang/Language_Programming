/*************************************************************************
	> File Name: flush.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Fri 22 May 2015 05:10:22 PM HKT
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

/**
 * usage:
 * ./flushline
 * ./flushline > result
 * you will see the difference, you can use standard output follows the line cache, and the file not!
 */
int main(int argc,const char *argv[])
{
	printf("one\n");
	fork();
	printf("two\n");
    return 0;
}
