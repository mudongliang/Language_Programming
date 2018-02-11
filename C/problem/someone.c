/*************************************************************************
	> File Name: test.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Sat 12 Sep 2015 11:30:18 AM CST
 ************************************************************************/
#include<stdio.h>
#include<stdlib.h>

void a(int num){
	int *p = malloc(num * sizeof(int));
	int i;
	for (i = 0;i < num;i++){
		p[i] = i;
	}
	int n = num / 2;
	int *tmp = p;
	while(1){
		//printf("n = %d\n", n);
		for (i = 0;i < n;i++){
			tmp[i] = tmp[i*2+1];
		}
		//for (i = 0;i < n; i++){
		//	printf("%d\t", tmp[i]);
		//}
		//printf("\n");
		if (n == 1) {
			printf("%d\n", tmp[0]);
			break;
		}
		n = n/2;
	}
	free(p);
	p = NULL;
	tmp = NULL;
}

int main(int argc,const char *argv[])
{
	int i;
	for (i = 2;i < 32;i++){
		a(i);
	}
    return 0;
}
