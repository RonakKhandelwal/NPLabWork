#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdlib.h>
int main(){

    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch[1000];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    
    
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(9734);
    len = sizeof(address);
    
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if(result == -1) {
        perror("oops: client1");
        exit(1);
    }
   
  while(1){
   printf("Enter sex bitch:\n");
    gets(ch);
        write(sockfd, ch, 100);
        //fprintf(stdout,"lalal1");
//        fflush(stdout);
        read(sockfd, ch, 100);
        fprintf(stdout,"%s\n", ch);
        fflush(stdout);
        
        }
    
    close(sockfd);
    exit(0);
}   
