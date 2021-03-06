#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define BUFLEN 512  
#define PORT 8888   
 
#define LENGTH 512
int main(void)
{
    struct sockaddr_in si_me, si_other;
     
    int s, i, slen = sizeof(si_other) , recv_len;
    char buf[BUFLEN];
     
    
    if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
    {
                   exit(0);
    }
     
    
    memset((char *) &si_me, 0, sizeof(si_me));
     
    si_me.sin_family = AF_INET;
    si_me.sin_port = htons(PORT);
    si_me.sin_addr.s_addr = htonl(INADDR_ANY);
     
    
    if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
    {
                    exit(0);
    }
     
     
     char* fr_name = "rec.cpp";
    		FILE *fr = fopen(fr_name, "w");
    
    
        memset((char *) &si_me, 0, sizeof(si_me));
        printf("Waiting for data...");
        fflush(stdout);
         
        
        while((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) >0)
        {
        printf("Data being wrriten\n");
        printf("%s",buf);
            int write_sz = fwrite(buf, sizeof(char), recv_len, fr);
            bzero(buf, 512);
				if (recv_len == 0 || recv_len != 512) 
				{
					break;
				}
        }
        
        fclose(fr);
        system("chmod +x rec.cpp");
		system("g++ rec.cpp");
		system("./a.out > res.txt");
		
		
		
		 char* fs_name = "res.txt";
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
			
         
        
        
			
         
        
        
    
 
    close(s);
    return 0;
}
