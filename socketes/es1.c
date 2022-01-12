#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<errno.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

#define SERVER_PORT 1313
#define SOCKET_ERRORE ((int)-1)

int main(int argc, char *argv[])
{
    struct sockaddr_in servizio, rem_indirizzo;
    int nread, soa, socketfd, fd, clientlen= sizeof(rem_indirizzo), on=1;
    char carattere, lettera= 'z';

    memset((char*)&servizio, 0, sizeof(servizio));

    servizio.sin_family= AF_INET;
    servizio.sin_port= htons(SERVER_PORT);
    servizio.sin_addr.s_addr=htonl(INADDR_ANY);

    socketfd=socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(socketfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on));

    bind(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

    listen(socketfd, 10);

    for(;;)
    {
        printf("\n\nserver in attesa\n");

        fflush(stdout);

        soa = accept(socketfd, (struct sockaddr *)&rem_indirizzo, &clientlen);

        nread = read(soa, &carattere, sizeof(carattere));
        printf("ricevito %c", carattere);
        write(soa, &lettera, sizeof(lettera));

        close(soa);

    }
    close(socketfd);
    return 0;
}
