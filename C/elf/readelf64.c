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

#define Elf_Ehdr Elf64_Ehdr
#define Elf_Shdr Elf64_Shdr

void usage(){
	printf("Usage: readelf elf-file\n");
	exit(-1);
}

void printElfHeader(Elf_Ehdr *elfheader){
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
	printf("  Entry point address:                 0x%lux\n",elfheader->e_entry);
	printf("  Start of program headers:            %lu (bytes into file)\n",elfheader->e_phoff);
	printf("  Start of section headers:            %lu (bytes into file)\n",elfheader->e_shoff);
	printf("  Flags:                               0x%ux\n",elfheader->e_flags);
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
	Elf_Shdr strhdr,shdr;
	unsigned char *strtable;
	int shnum;
	if(argc != 2) {
		usage();	
	}
	fp = fopen(argv[1], "r");
	if(fp == NULL) {
		usage();
	}
	fread(&elfheader, sizeof(char), sizeof(elfheader), fp);
	/*print out the elf header infomation here*/
	printElfHeader(&elfheader);

 	fseek(fp, elfheader.e_shoff + elfheader.e_shstrndx * elfheader.e_shentsize, SEEK_SET);
    fread(&strhdr, sizeof(char), sizeof(strhdr), fp); 
	/* get the string table header */
    fseek(fp, strhdr.sh_offset, SEEK_SET);
    strtable = (unsigned char *)malloc(sizeof(unsigned char)*strhdr.sh_size);
    fread(strtable, sizeof(char), strhdr.sh_size, fp);
    fseek(fp, elfheader.e_shoff, SEEK_SET);
    shnum = elfheader.e_shnum;
    printf("There are %d section headers, starting at offset 0x%lux\n", shnum,elfheader.e_shoff);
    while(shnum != 0){
        fread(&shdr, sizeof(char), sizeof(shdr), fp);
        printf("sh_name : %s\n", strtable+shdr.sh_name);
        printf("sh_type : %u\n", shdr.sh_type);
        printf("sh_flags : %lu\n", shdr.sh_flags);
        printf("sh_addr : %lu\n", shdr.sh_addr);
        printf("sh_offset : %lu\n", shdr.sh_offset);
        printf("sh_size : %lu\n", shdr.sh_size);
        printf("sh_link : %u\n", shdr.sh_link);
        printf("sh_info : %u\n", shdr.sh_info);
        printf("sh_addralign : %lu\n", shdr.sh_addralign);
        printf("sh_entsize : %lu\n\n", shdr.sh_entsize);
        shnum--;
    }
	free(strtable);
	strtable = NULL;
	return 0;
}
