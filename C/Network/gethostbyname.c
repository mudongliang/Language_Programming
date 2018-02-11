/*************************************************************************
	> File Name: gethostbyname.c
	> Author: mudongliang
	> Mail: mudongliangabcdi@163.com
	> Created Time: Fri 20 Nov 2015 07:53:01 PM CST
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <arpa/inet.h>

//struct hostent *gethostbyname(const char *name);

int main(int argc,const char *argv[])
{
	if (argv[1] == NULL){
		printf("help: %s hostname\n", argv[0]);
		exit(0);
	}
	char str[50];
	struct hostent *ht = malloc(sizeof(struct hostent));
	if ((ht = gethostbyname(argv[1])) == NULL){
		printf("error happens\n");
	}
	printf("offical name = %s\n", ht->h_name);
	int i = 0;
	while(ht->h_addr_list[i]){
		printf("addr[%d] = %s\n", i, inet_ntop(ht->h_addrtype, ht->h_addr_list[i], str, sizeof(str)));
		i++;
	}
    return 0;
}
