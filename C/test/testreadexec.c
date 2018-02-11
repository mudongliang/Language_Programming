#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>

#define handle_error(msg) \
    do { perror(msg); exit(EXIT_FAILURE); } while (0)

static char *buffer;

#define PRINTMAPS

int main()
{
    int pagesize;
	char command[20];

    pagesize = sysconf(_SC_PAGE_SIZE);
	printf("Page Size is %x\n",pagesize);
    if (pagesize == -1)
        handle_error("sysconf");

    /* Allocate a buffer aligned on a page boundary;
       initial protection is PROT_READ | PROT_WRITE */

    buffer = mmap((void *)0x600000000000, 20 * pagesize, PROT_READ | PROT_EXEC, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (buffer == MAP_FAILED)
        handle_error("mmap");

#ifdef PRINTMAPS
	int pid = getpid();
	sprintf(command,"cat /proc/%d/maps",pid);
	printf("%s\n",command);
	system(command);
#endif

	exit(EXIT_SUCCESS);
}
