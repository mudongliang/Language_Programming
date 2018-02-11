/*************************************************************************
	> File Name: a.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Sun 04 Oct 2015 01:14:26 PM CST
 ************************************************************************/

#include<stdio.h>

char mag[]  = "\x7fELF";	//wrong
char mag1[] = "\x7f ELF";	//wrong
char mag2[] = "\177ELF";	//right

int main()
{
	char *a = NULL;
	for( a = &mag; *a ; a++)
		printf("%d and %x\n", *a, *a);
	printf("--- ---\n");
	for( a = &mag1 ; *a ; a++)
		printf("%d and %x\n", *a, *a);
	printf("--- ---\n");
	for( a = &mag2 ; *a ; a++)
		printf("%d and %x\n", *a, *a);
	printf("--- ---\n");
    return 0;
}
