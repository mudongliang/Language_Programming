#include <stdio.h>  
#include <unistd.h>  
#include <stdlib.h>  
#include <errno.h>  

int main() {  
    pid_t pid=vfork();  
    if(pid==0) {  
		printf("i am the child process, my process id is %d\n",getpid());   
		printf("我是爹的儿子\n");//对某些人来说中文看着更直白 
    }  
    else if (pid > 0) {  
		printf("i am the parent process, my process id is %d\n",getpid());   
		printf("我是孩子他爹\n");  
		_exit(0); //可以去man vfork去寻找这一行的作用，没有这样会出问题
    }
    else {  
        fprintf(stderr,"can't fork ,error %d\n",errno);  
        exit(1);  
    }  
	return 0;
}
