#include "header.h"
#include "func.c"
#define PORT 4444

int main(int argc, char *argv[]){

    int clientSocket, ret;
    struct sockaddr_in serverAddr;
    char bufferU[1024], bufferP[1024];

	clientSocket = socket(AF_INET, SOCK_STREAM, 0);
	if(clientSocket < 0){
        printf("[-]Error in connection.\n");
        exit(1);
	}
    printf("[+]Client Socket is created.\n");

    memset(&serverAddr, '\0', sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1");

	ret = connect(clientSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if(ret < 0){
        printf("[-]Error in connection.\n");
        exit(1);
    }
    printf("[+]Connection to server.\n");

    while(1){
        printf("Usuario: \t");
        scanf("%s", &bufferU[0]);
        send(clientSocket, bufferU, strlen(bufferU), 0);

        if(strcmp(bufferU, "exit") == 0){
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
            exit(1);
        }

        if(recv(clientSocket, bufferU, 1024, 0) < 0){
            printf("[-]Error in receiving data.\n");
        } else {
            printf("Server: \t%s\n", bufferU);
        }
        printf("Contraseña: \t");
        scanf("%s", &bufferP[0]);
        send(clientSocket, bufferP, strlen(bufferP), 0);

        if(strcmp(bufferP, "exit") == 0){
            close(clientSocket);
            printf("[-]Disconnected from server.\n");
            exit(1);
        }

        if(recv(clientSocket, bufferP, 1024, 0) < 0){
            printf("[-]Error in receiving data.\n");
        } else {
            printf("Server: \t%s\n", bufferP);
        }
    }


	return 0;
}
