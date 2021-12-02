#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <ctype.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>

#define DIMBUFF 512
#define SERVER_PORT 1313

typedef struct
{
	char nome[50];
	char cognome[100];
	char numTelefono[10];
}contatto_t;

int Load(contatto_t array[], char inputFileName[])
{
	FILE *inputFile = fopen(inputFileName, "r");
	int contattoQta = 0;
	
	while(!feof(inputFile))
	{
		fscanf(inputFile, "%s%s%s\n", array[contattoQta].nome, array[contattoQta].cognome, array[contattoQta].numTelefono);
		
		printf("%s %s %s\n", array[contattoQta].nome, array[contattoQta].cognome, array[contattoQta].numTelefono);
		contattoQta++;
	}
	
	fclose(inputFile);
	return contattoQta;
}

void Write(contatto_t array[], int contattoQta, char outputFileName[])
{
	FILE *outputFile = fopen(outputFileName, "w");
	for(int i = 0; i < contattoQta; i++)
	{
			fprintf(outputFile, "%s %s %s\n", array[i].nome, array[i].cognome, array[i].numTelefono);
	}
	fclose(outputFile);
}

int main(int argc, char *argv[])
{
	if(argc == 5)
	{
		struct sockaddr_in servizio;
		contatto_t rubrica[100];
		int nread, socketfd;
		int contattoQta = Load(rubrica, argv[3]);

		memset((char *)&servizio, 0, sizeof(servizio));

		servizio.sin_family = AF_INET;       //dominio di comunicazione (internet) Address family
		servizio.sin_addr.s_addr = inet_addr(argv[1]);  //indirizzo
		servizio.sin_port = atoi(argv[2]);	//porta

		socketfd = socket(AF_INET, SOCK_STREAM, 0);

		connect(socketfd, (struct sockaddr *)&servizio, sizeof(servizio));

		write(socketfd, rubrica, sizeof(rubrica[0])* contattoQta);

	//ricevere i dati dal client
		nread = read(socketfd, rubrica, sizeof(rubrica[0])* contattoQta);

		Write(rubrica, contattoQta, argv[4]);
	//chiusura socket
		close(socketfd);
		return 0;
	}
	else
	{
		printf("Parametri inseriti errati. Reinserire correttamente.\n");
		return(1);
	}
}
