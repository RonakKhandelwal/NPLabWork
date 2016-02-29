#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
#include<arpa/inet.h>
#include<sys/socket.h>
 #include <unistd.h>
#define BUFLEN 512  
#define PORT 8888   
 

int main(void)
{
    struct sockaddr_in si_me, si_other;
     
    int s, i, slen = sizeof(si_other) , recv_len;
    char buf[BUFLEN];
     
    
    if ((s=socket(AF_INET,SOCK_DGRAM, IPPROTO_UDP)) == -1)
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
     
    
    while(1)
    {
        memset((char *) &si_me, 0, sizeof(si_me));
        printf("Waiting for data...");
        fflush(stdout);
         
        
        if ((recv_len = recvfrom(s, buf, BUFLEN, 0, (struct sockaddr *) &si_other, &slen)) == -1)
        {
            exit(0);
        }
         
        else{
            int pid;
            pid=fork();
            if(pid == 0){
                fprintf(stdout,"Process with pid %d handling this one with the parent %d\n",getpid(),getppid());
                
                fprintf(stdout,"Data: %s\n" , buf);
         
        
                if (sendto(s, buf, recv_len, 0, (struct sockaddr*) &si_other, slen) == -1)
                {
                    exit(0);
                }
                memset((char *) &si_me, 0, sizeof(si_me));
            
            }
        
        }
        
    }
 
    close(s);
    return 0;
}
