#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>

int main()
{
	char *p = malloc(1024);	// to show heap segment
	int pagesize = sysconf(_SC_PAGE_SIZE);
	char *buffer = mmap(0,4*pagesize,PROT_READ|PROT_WRITE,MAP_ANONYMOUS|MAP_PRIVATE,-1,0);
	// to show memory mapping region
	if(buffer == MAP_FAILED)
		perror("mmap failed!\n");	

	char command[50];
	int pid = getpid();
	sprintf(command,"cat /proc/%d/maps",pid);
	//printf("%s\n",command);
	system(command);
	return 0;
}
