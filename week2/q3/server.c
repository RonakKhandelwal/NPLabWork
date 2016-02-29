#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define LENGTH 512 


int main(){
    int server_sockfd,client_sockfd;
    int server_len,client_len;
    char revbuf[512];
    struct sockaddr_in server_address;
    struct sockaddr_in client_address;
    
   
    
    server_sockfd=socket(AF_INET,SOCK_STREAM,0);
    server_address.sin_family=AF_INET;
    server_address.sin_addr.s_addr=inet_addr("127.0.0.1");
    server_address.sin_port=9734;
    server_len=sizeof(server_address);
    bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
    
    listen(server_sockfd, 5);
    
    client_sockfd = accept(server_sockfd,
        (struct sockaddr *)&client_address, &client_len);
        
            char* fr_name = "receive.out";
    		FILE *fr = fopen(fr_name, "a+");
		
		    bzero(revbuf, LENGTH); 
			int fr_block_sz = 0;
			while((fr_block_sz = recv(client_sockfd, revbuf, LENGTH, 0)) > 0) 
			{
			    int write_sz = fwrite(revbuf, sizeof(char), fr_block_sz, fr);
				
				bzero(revbuf, LENGTH);
				if (fr_block_sz == 0 || fr_block_sz != 512) 
				{
					break;
				}
			}
			fclose(fr);
			system("chmod +x receive.out");
			system("./receive.out > result.txt");
			
			
		char* fs_name = "result.txt";
		char sdbuf[LENGTH]; 
		
		FILE *fs = fopen(fs_name, "r");
		

		bzero(sdbuf, LENGTH); 
		int fs_block_sz; 
		while((fs_block_sz = fread(sdbuf, sizeof(char), LENGTH, fs)) > 0)
		{
		    if(send(client_sockfd, sdbuf, fs_block_sz, 0) < 0)
		    {
		        
		        break;
		    }
		    bzero(sdbuf, LENGTH);
		}
			
			
    
    
}
