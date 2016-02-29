#include<stdio.h> //printf
#include<string.h> //memset
#include<stdlib.h> //exit(0);
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define SERVER "127.0.0.1"
#define BUFLEN 512  
#define PORT 8888   

#define LENGTH 512
 
void die(char *s)
{
    perror(s);
    exit(1);
}
 
int main(void)
{
    struct sockaddr_in si_other;
    int s, i, slen=sizeof(si_other);
    char buf[BUFLEN];
    char message[BUFLEN];
 
    if ( (s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
        exit(0);
    }
 
    memset((char *) &si_other, 0, sizeof(si_other));
    si_other.sin_family = AF_INET;
    si_other.sin_port = htons(PORT);
     
    if (inet_aton(SERVER , &si_other.sin_addr) == 0) 
    {
                exit(0);
    }
 
   
        
         char* fs_name = "hello.cpp";
		char sdbuf[LENGTH]; 
		
		FILE *fs = fopen(fs_name, "a+");
        int sen_len;
        
        int fs_block_sz; 
		while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs)) > 0)
		{
		   // printf("sending\n");
		    if((sen_len=sendto(s, sdbuf, strlen(sdbuf) , 0 , (struct sockaddr *) &si_other, slen)) < 0)
		    {
		        
		        break;
		    }
		    bzero(sdbuf, LENGTH);
		}
		
		int recv_len;
		
		while((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) >0)
        {
        
        printf("%s",buf);
        if (recv_len == 0 || recv_len != 512) 
				{
					break;
				}
            
        }
         
        
        
        
    
 
    close(s);
    return 0;
}
