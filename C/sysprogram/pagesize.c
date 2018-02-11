/*************************************************************************
	> File Name: pagesize.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: 2015年09月23日 星期三 19时26分54秒
 ************************************************************************/

#include<stdio.h>
#include<unistd.h>

int main()
{
	long pagesize = sysconf(_SC_PAGESIZE);
	printf("pagesize of your system is 0x%lx\n", pagesize);
	
	pagesize = getpagesize();
	printf("pagesize of your system is 0x%lx\n", pagesize);
    return 0;
}
