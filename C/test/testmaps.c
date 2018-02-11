#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	char command[50];
	int pid = getpid();
	sprintf(command,"cat /proc/%d/maps",pid);
	//printf("%s\n",command);
	system(command);
	return 0;
}
