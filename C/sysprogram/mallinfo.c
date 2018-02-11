/*************************************************************************
	> File Name: mallinfo.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: 2015年09月23日 星期三 22时29分33秒
 ************************************************************************/

#include<stdio.h>
#include<malloc.h>

int main(int argc,const char *argv[])
{
	struct mallinfo m;
	m = mallinfo();
	printf("Free chunks: %d\n", m.ordblks);
    return 0;
}
