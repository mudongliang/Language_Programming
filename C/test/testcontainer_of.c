/*************************************************************************
	> File Name: testcontainer_of.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Tue 06 Oct 2015 02:36:00 PM CST
 ************************************************************************/

#include<stdio.h>
struct container{
	int field1;
	char field2;
	char field3;
};

int main()
{
	printf("%p\n", &((struct container*)0)->field3);
    return 0;
}
