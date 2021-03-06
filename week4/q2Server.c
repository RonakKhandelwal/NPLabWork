#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int main(){

	int server_sockfd, client_sockfd;
	int server_len, client_len, isTimeout;

	struct sockaddr_in server_address;
	struct sockaddr_in client_address;

	fd_set readfds;
	struct timeval timeout;
	
	server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = 9800;
	server_len = sizeof(server_address);
	bind(server_sockfd, (struct sockaddr *)&server_address, server_len);
	
	FD_ZERO(&readfds);
	listen(server_sockfd, 5);
	while(1) {
		printf("server waiting\n");
		timeout.tv_sec = 5;
		timeout.tv_usec = 0;
		FD_SET(server_sockfd, &readfds);
		isTimeout = select(FD_SETSIZE, &readfds, NULL, NULL, &timeout);
		if(isTimeout == 0)
			printf("NANANANANANANANNANAN BATMAN\n");
		else{

			client_len = sizeof(client_address);
			if(FD_ISSET(server_sockfd, &readfds)){

				client_sockfd = accept(server_sockfd,
				(struct sockaddr *)&client_address, &client_len);
				time_t rawtime;
				time(&rawtime);
				write(client_sockfd, &rawtime, sizeof(rawtime));
				close(client_sockfd);
			}
			
		}
	}
}
