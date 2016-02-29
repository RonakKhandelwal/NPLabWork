#include <sys/types.h>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

int main(){

	int sockfd;
	int len;
	struct sockaddr_in address;
	int result;
	char request[100];
	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_port = 9800;
	len = sizeof(address);

	result = connect(sockfd, (struct sockaddr *)&address, len);
	if(result == -1) {
		perror("oops: client1");
		return 0;
	}
	time_t rawtime;	
	read(sockfd, &rawtime, sizeof(rawtime));
	struct tm * timeinfo;
	timeinfo = localtime(&rawtime);
	printf("Time and date : %s", asctime(timeinfo));
	close(sockfd);
	return 0;
}
