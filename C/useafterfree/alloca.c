#include<stdio.h> 
#include<alloca.h>
char *gp = NULL;
#define N 100
void subfun(){
	gp = (char *) alloca(N);
	printf("backdoor on the stack is generated!\n");
}

int main(){
	subfun();
	*(gp+20) = '1';
	// then we can use pointer gp to control the stack
	return 0;
}
