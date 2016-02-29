#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(){

	char b;
	char f1[200];
	printf("Please Enter File to read from: ");
	scanf("%s",f1);
	int fhandle = open(f1,O_RDONLY,0600);
    int nfhandle = open("copiedfile.txt", O_WRONLY | O_CREAT, 0700);
    while(read(fhandle,&b,1)==1)
        write(nfhandle,&b,1);
    close(fhandle);
    close(nfhandle);
	return 0;
}
