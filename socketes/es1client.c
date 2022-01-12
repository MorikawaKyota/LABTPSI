#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define SERVER_PORT 1313

int main (int argc, char *argv[])
{
    struct sockaddr_in servizio;
    int nread, socketfd;
    char carattere=argv[1][0];

    memset((char*)&servizio, 0, sizeof(servizio));

    servizio.sin_family= AF_INET;
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);
    servizio.sin_port=htons(SERVER_PORT);

    socketfd = socket(AF_INET, SOCK_STREAM, 0);

    connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    write(socketfd, &carattere, sizeof(carattere));

    read(socketfd, &carattere, sizeof(carattere));
    printf("riceto %c\n", carattere);
    close(socketfd);

    return 0;
}