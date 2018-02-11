/*************************************************************************
	> File Name: malloc_chunk.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 23 Nov 2015 10:24:08 PM CST
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
int main()
{
	char *A, *B, *C, *D;
	A = malloc(0x100 - 8);
	B = malloc(0x100 - 8);
	C = malloc(0x80 - 8);
	D = malloc(0x80 - 8);

	printf("A chunk: %p -> %p\n", A, A + 0x100 - 8);
	printf("B chunk: %p -> %p\n", B, B + 0x100 - 8);
	printf("C chunk: %p -> %p\n", C, C + 0x80 - 8);
	printf("D chunk: %p -> %p\n", D, D + 0x80 - 8);

//	free(A);
	free(B);
	free(D);

//	printf("%p -> %08x\n", A - 8, *(A - 8));	
//	printf("%p -> %08x\n", A - 4, *(A - 4));	
	printf("%p -> %08x\n", A - 8, *(A + 0x100 - 8));	
	printf("%p -> %08x\n", A - 4, *(A + 0x100 - 4));	
	printf("%p -> %08x\n", A, *(A));	
	printf("%p -> %08x\n", A + 4, *(A + 4));	
	printf("\n");

	printf("%p -> %08x\n", A + 0x100 - 8, *(A + 0x100 - 8));	
	printf("%p -> %08x\n", A + 0x100 - 4, *(A + 0x100 - 4));	
	printf("%p -> %08x\n", A + 0x100, *(A + 0x100));	
	printf("%p -> %08x\n", A + 0x100 + 4, *(A + 0x100 + 4));	
	printf("\n");

	printf("%p -> %08x\n", C - 8, *(C - 8));	
	printf("%p -> %08x\n", C - 4, *(C - 4));	
	printf("%p -> %08x\n", C, *(C));	
	printf("%p -> %08x\n", C + 4, *(C + 4));	
	printf("\n");

	printf("%p -> %08x\n", D - 8, *(D - 8));	
	printf("%p -> %08x\n", D - 4, *(D - 4));	
	printf("%p -> %08x\n", D, *(D));	
	printf("%p -> %08x\n", D + 4, *(D + 4));	

	B = malloc(0x100 + 0x80 - 8);

	printf("B chunk: %p -> %p\n", B, B + 0x100 +0x80 - 8);
	return 0;
}
