#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <errno.h>  

int main() {  
    pid_t pid=fork();  
    if(pid==0) {  
		printf("i am the child process, my process id is %d\n",getpid());   
		printf("我是爹的儿子\n");//对某些人来说中文看着更直白。  
    }  
    else if (pid > 0) {  
		printf("i am the parent process, my process id is %d\n",getpid());   
		printf("我是孩子他爹\n");  
    }
    else {  
        fprintf(stderr,"can't fork ,error %d\n",errno);  
        exit(1);  
    }  
    printf("This is the end !\n");  
	return 0;
}
