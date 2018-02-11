/*************************************************************************
	> File Name: showelfheader.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Tue 19 May 2015 07:59:37 PM CST
 ************************************************************************/

#include <stdio.h>
#include <elf.h>
#include <stdlib.h>
#include <string.h>

#define Elf_Ehdr Elf32_Ehdr

void usage(){
	printf("Usage: readelf elf-file\n");
	exit(-1);
}

void print(Elf_Ehdr *elfheader){
	int index = 0;
	char machine[30],type[30];
	printf("ELF Header:\n");
	printf("  Magic:   ");
	for(index = 0; index < EI_NIDENT; index++){
		printf("%2x ",elfheader->e_ident[index]);
	}
	printf("\n");
	switch(elfheader->e_type){
		case ET_NONE:
			strcpy(type,"No file type");
			break;
		case ET_REL:
			strcpy(type,"Relocatable file");
			break;
		case ET_EXEC:
			strcpy(type,"Executable file");
			break;
		case ET_DYN:
			strcpy(type,"Shared object file");
			break;
		case ET_CORE:
			strcpy(type,"Core file");
			break;
		default:
			strcpy(type,"unvalid code");
			break;
	}
	printf("  Type:                                %s\n",type);
	strcpy(machine,"uncomplete");
	printf("  Machine:                             %s\n",machine);
	printf("  Version:                             0x%u\n",elfheader->e_version);
	printf("  Entry point address:                 0x%x\n",elfheader->e_entry);
	printf("  Start of program headers:            %u (bytes into file)\n",elfheader->e_phoff);
	printf("  Start of section headers:            %u (bytes into file)\n",elfheader->e_shoff);
	printf("  Flags:                               0x%x\n",elfheader->e_flags);
	printf("  Size of this header:                 %u (bytes)\n",elfheader->e_ehsize);
	printf("  Size of program headers:             %u (bytes)\n",elfheader->e_phentsize);
	printf("  Number of program headers:           %u\n",elfheader->e_phnum);
	printf("  Size of section headers:             %u (bytes)\n",elfheader->e_shentsize);
	printf("  Number of section headers:           %u\n",elfheader->e_shnum);
	printf("  Section header string table index:   %u\n",elfheader->e_shstrndx);
}

int main(int argc,const char *argv[])
{
	FILE *fp;
	Elf_Ehdr elfheader;
	if(argc != 2) {
		usage();	
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		usage();
	}
	fread(&elfheader, sizeof(char), sizeof(elfheader), fp);
	/*print out the elf header infomation here*/
	print(&elfheader);
	return 0;
}
