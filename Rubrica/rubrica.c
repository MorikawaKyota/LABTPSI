#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[50];
	char cognome[100];
	char numTelefono[10];
}contatto_t;

void Load(contatto_t array[], size_t size, char inputFileName[])
{
	FILE *inputFile = fopen(inputFileName, "r");
	char line[100];
	
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		if(fscanf(inputFile, "%s", line) == 1)
		{
			char delimiter[] = " ";
			char* tokens = strtok(line, delimiter);
			strcpy(array[i].nome, tokens);
			tokens = strtok(NULL, delimiter);
			strcpy(array[i].cognome, tokens);
			tokens = strtok(NULL, delimiter);
			strcpy(array[i].numTelefono, tokens);
		}
		else
		{
			break;
		}
	}

}

void ShowContatti(contatto_t array[], size_t size)
{
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		if(array[i].nome != NULL)
		{
			printf("%s %s %s\n", array[i].nome, array[i].cognome, array[i].numTelefono);
		}
		else
		{
			break;
		}
	}
}

void AddContatto(contatto_t array[], size_t size)
{
	printf("Inserire i dati del nuovo contatto secondo il formato 'nome cognome numero telefonico'\n");
	char newContatto[100];
	scanf("%s", newContatto);
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		if(array[i].nome == NULL)
		{
			char delimiter[] = " ";
			char* tokens = strtok(newContatto, delimiter);
			strcpy(array[i].nome, tokens);
			tokens = strtok(NULL, delimiter);
			strcpy(array[i].cognome, tokens);
			tokens = strtok(NULL, delimiter);
			strcpy(array[i].numTelefono, tokens);
		}	
	}
}

int SearchContatto(contatto_t array[], size_t size, char numTel[])
{
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		if(array[i].nome == NULL)
		{
			return -1;
		}
		if(strcmp(numTel, array[i].numTelefono) == 0)
		{
			return i;
		}
	}
}

void EliminateContatto(contatto_t array[], size_t size)
{
	printf("Indicare il numero telefonico del contatto che vuoi eliminare.\n");
	char contattoNumTel[100];
	scanf("%s", contattoNumTel);
	int indexContatto = SearchContatto(array, size, contattoNumTel);
	if(indexContatto != -1)
	{
		for(indexContatto; indexContatto < (size / sizeof(array[0])) - 1; indexContatto++)
		{
			strcpy(array[indexContatto].nome, array[indexContatto + 1].nome);
			strcpy(array[indexContatto].cognome, array[indexContatto + 1].cognome);
			strcpy(array[indexContatto].numTelefono, array[indexContatto + 1].numTelefono);
		}
	}
	else
	{
		printf("Il contatto non esiste nella rubrica.\n");
	}
}

void Write(contatto_t array[], size_t size, char outputFileName[])
{
	FILE *outputFile = fopen(outputFileName, "w");
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		if(array[i].nome != NULL)
		{
			fprintf(outputFile, "%s %s %s\n", array[i].nome, array[i].cognome, array[i].numTelefono);
		}
		else
		{
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	contatto_t contatti[50];
	size_t size = sizeof contatti;
	
	if(argc == 2 || (argc == 4 && strcmp(argv[2], "-f") == 0))
	{
		Load(contatti, size, argv[1]);
		
		char option;
		do
		{
			printf("Scegliere l'opzione da svolgere:\n");
			printf("1) mostrare la rubrica a video\n");
			printf("2) aggiungere un contatto alla rubrica\n");
			printf("3) eliminare un contatto dalla rubrica dopo averlo ricercato con il suo numero di telefono\n");
			printf("4)Terminare il programma\n");
			scanf("%c", &option);
			
			switch(option)
			{
				case '1':
					{
						ShowContatti(contatti, size);
						break;
					}
				case '2':
					{
						AddContatto(contatti, size);
						break;
					}
				case '3':
					{
						EliminateContatto(contatti, size);
						break;
					}
				case '4':
					{
						if(argc == 2)
						{
							Write(contatti, size, argv[1]);
						}
						else
						{
							Write(contatti, size, argv[3]);
						}
						break;
					}
				default:
					{
						printf("Opzione errata. Riprovare.\n");
						break;
					}
			}
		}while(option != '4');
	}
	else
	{
		printf("Hai inserito valori errati, riprova.\n");
	}
	return 0;
}
