#include "header.h"
#include "func.c"

#define PORT 4444

int main(int argc, char *argv[]){

    int sockfd, ret;
    struct sockaddr_in serverAddr;

	int newSocket;
    struct sockaddr_in newAddr;

    socklen_t addr_size;

    char bufferU[1024], bufferP[1024], bufferE[1024], bufferF[1024], bufferEs[1024];
    pid_t childpid;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
        printf("[-]Error in connection.\n");
        exit(1);
	}
    printf("[+]Server Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    ret = bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        printf("[-]Error in binding.\n");
        exit(1);
    }
    printf("[+]Bind to port %d\n", 4444);

    if(listen(sockfd, 10) == 0){
        printf("Listening....\n");
    } else {
        printf("[-]Error in binding.\n");
    }

    while(1){
		newSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
        if(newSocket < 0){
            exit(1);
        }
        printf("Connection accepted from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));

        if((childpid = fork()) == 0){
            close(sockfd);

            while(1){
                recv(newSocket, bufferU, 1024,0);
                if(strcmp(bufferU, "exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                } else {
                    printf("Usuario: %s\n", bufferU);
                    send(newSocket, bufferU, strlen(bufferU), 0);
                    bzero(bufferU, sizeof(bufferU));
                }

                recv(newSocket, bufferP, 1024,0);
                if(strcmp(bufferP, "exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                } else {
                    printf("Contraseņa: %s\n", bufferP);
                    send(newSocket, bufferP, strlen(bufferP), 0);
                    bzero(bufferP, sizeof(bufferP));
                }

                recv(newSocket, bufferE, 1024,0);
                if(strcmp(bufferE, "exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                } else {
                    printf("Eleccion: %s\n", bufferE);
                    send(newSocket, bufferE, strlen(bufferE), 0);
                    bzero(bufferE, sizeof(bufferE));
                }

                recv(newSocket, bufferF, 1024,0);
                if(strcmp(bufferF, "exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                } else {
                    printf("Fecha: %s\n", bufferF);
                    send(newSocket, bufferF, strlen(bufferF), 0);
                    bzero(bufferF, sizeof(bufferF));
                }

                recv(newSocket, bufferEs, 1024,0);
                if(strcmp(bufferEs, "exit") == 0){
                    printf("Disconnected from %s:%d\n", inet_ntoa(newAddr.sin_addr), ntohs(newAddr.sin_port));
                    break;
                } else {
                    printf("Estudiante: %s\n", bufferEs);
                    send(newSocket, bufferEs, strlen(bufferEs), 0);
                    bzero(bufferEs, sizeof(bufferEs));
                }
            }
        }
    }

    close(newSocket);

	return 0;
}
