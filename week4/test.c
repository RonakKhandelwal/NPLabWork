#include <fcntl.h>


int main(){
    int fd=open("lol.txt",O_APPEND);
    
    char a[100];
int w=    scanf("%s",a);
    write(fd,a,w);

}
