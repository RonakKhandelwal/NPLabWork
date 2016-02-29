#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 20000
#define LENGTH 512 

int main(){
    int sockfd;
    int len;
    struct sockaddr_in address;
    int result;
    char ch[1024];
    sockfd = socket(AF_INET,SOCK_STREAM,0);
    
    address.sin_family=AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port=9734;
    len=sizeof(address);
    
    char c;
    if(result == -1){
        perror("oops:client1");
        exit(1);
    }
    
     result = connect(sockfd,(struct sockaddr *)&address,len);
    
    char* fs_name = "a.out";
		char sdbuf[LENGTH]; 
		
		FILE *fs = fopen(fs_name, "a+");
		

		bzero(sdbuf, LENGTH); 
		int fs_block_sz; 
		while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs)) > 0)
		{
		    if(send(sockfd, sdbuf, fs_block_sz, 0) < 0)
		    {
		        
		        break;
		    }
		    bzero(sdbuf, LENGTH);
		}
		printf("Ok File %s from Client was Sent!\n", fs_name);
		
		
		  char revbuf[512];
			int fr_block_sz = 0;
			while((fr_block_sz = recv(sockfd, revbuf, LENGTH, 0)) > 0) 
			{
			   printf("%s",revbuf);
				
				bzero(revbuf, LENGTH);
				if (fr_block_sz == 0 || fr_block_sz != 512) 
				{
					break;
				}
			}
		
    
  //  write(sockfd,&ch,1024);
    fclose(fs);
    close(sockfd);
    
    
    //printf("chat from server=%d\n",ch);
    
    exit(0);
    
}
