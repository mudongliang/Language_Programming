/*************************************************************************
	> File Name: struct.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Thu 10 Sep 2015 03:07:22 PM CST
 ************************************************************************/

#include<stdio.h>

struct value{
	int value;
	int start;
};

#define LEN 10

int main(int argc,const char *argv[])
{
	struct value a = {
		.value = 1,
		.start = 1
	};
	printf("---%d %d---\n", a.value, a.start);

	int id;
	
	int i[LEN] = {3};
	for(id = 0; id < LEN; id++){
		printf("---%d---\n", i[id]);
	}
	printf("------");

	struct value c[LEN] = {{3,3}};
	for(id = 0; id < LEN; id++){
		printf("---%d %d---\n", c[id].value, c[id].start);
	}
	printf("------");

    return 0;
}
