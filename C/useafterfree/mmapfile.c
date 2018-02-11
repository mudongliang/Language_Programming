/*************************************************************************
	> File Name: mmapfile.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Mon 23 Nov 2015 04:53:42 PM CST
 ************************************************************************/

#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/mman.h>

int main(int argc,const char *argv[])
{
	struct stat sb;
	off_t len;
	char *p;
	int fd;

	if (argc != 2){
		fprintf(stderr, "usage : %s <file>\n", argv[0]);
		return 1;
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1){
		perror("open error");
		return 1;
	}

	if (fstat(fd, &sb) == -1){
		perror("fstat error");
		return -1;
	}

	if (!S_ISREG(sb.st_mode)){
		fprintf(stderr, "%s is not a file\n", argv[1]);
		return 1;
	}

	p = mmap(0, sb.st_size, PROT_READ, MAP_SHARED, fd, 0);
	if (p == MAP_FAILED){
		perror("mmap error");
		return 1;
	}

	if (close(fd) == -1){
		perror("close error");
		return -1;
	}

	for(len = 0; len < sb.st_size; len++)
		putchar(p[len]);

	if(munmap(p, sb.st_size) == -1){
		perror("munmap error");
		return 1;
	}
	
    return 0;
}
