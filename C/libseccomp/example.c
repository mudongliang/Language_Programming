/*************************************************************************
	> File Name: example.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Thu 07 Jan 2016 10:47:38 AM CST
 ************************************************************************/

#include<stdio.h>        /* printf */
#include<unistd.h>       /* dup2 : jsut for test */
#include<linux/seccomp.h>      /* seccomp's constants */
#include<sys/prctl.h>    /* prctl */

int main(int argc,const char *argv[])
{
	printf("step 1: unrestricted\n");

	//Enable filtering
	prctl(PR_SET_SECCOMP, SECCOMP_MODE_STRICT);
	printf("step 2: only 'read', 'write', '_exit' and 'sigreturn' syscall\n");

	//Redirect stderr to stdout
	dup2(1, 2);
	printf("step 3: !! You Should not see me!!");

    return 0;
}
