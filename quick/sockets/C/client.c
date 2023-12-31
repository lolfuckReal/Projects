#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>

struct sockaddr_in serv; //This is our main socket variable.
int fd; //This is the socket file descriptor that will be used to identify the socket
int conn; //This is the connection file descriptor that will be used to distinguish client connections.
char message[100] = "";

int main(int argc, char* argv[]) {
    fd = socket(AF_INET, SOCK_STREAM, 0);
    serv.sin_family = AF_INET;
    serv.sin_port = htons(8096);

    inet_pton(AF_INET, "127.0.0.1", &serv.sin_addr);
    connect(fd, (struct sockaddr*) &serv, sizeof(serv)); //This connects the client to the server.
    
    while(1) {
        printf("Enter a message: ");
        fgets(message, 100, stdin);
        send(fd, message, strlen(message), 0);
    }
}
