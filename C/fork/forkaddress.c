#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char *argv[]){
    char str[4]="asd";
    pid_t pid=fork();
    if(pid==0){
        str[0]='b';
        printf("子进程中str=%s\n",str);
        printf("子进程中str指向的首地址:%p\n",str);
    }
    else{
        sleep(1);
        printf("父进程中str=%s\n",str);
        printf("父进程中str指向的首地址:%p\n",str);
    }
	return 0;
}
