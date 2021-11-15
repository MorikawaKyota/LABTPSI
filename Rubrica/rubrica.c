#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
	char nome[50];
	char cognome[100];
	char numTelefono[10];
}contatto_t;

int Load(contatto_t array[], size_t size, char inputFileName[])
{
	FILE *inputFile = fopen(inputFileName, "r");
	char line[100];
	int contattoQta = 0;
	
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		if(fscanf(inputFile, "%s%s%s", line) == 1)
		{
			char delimiter[] = " ";
			char* tokens = strtok(line, delimiter);
			strcpy(array[i].nome, tokens);
			tokens = strtok(NULL, delimiter);
			strcpy(array[i].cognome, tokens);
			tokens = strtok(NULL, delimiter);
			strcpy(array[i].numTelefono, tokens);
			
			contattoQta++;
		}
		else
		{
			return contattoQta;
		}
	}

}

void ShowContatti(contatto_t array[], int contattoQta)
{
	for(int i = 0; i < contattoQta; i++)
	{
			printf("%s %s %s\n", array[i].nome, array[i].cognome, array[i].numTelefono);
	}
}

void AddContatto(contatto_t array[], int contattoQta)
{
	printf("Inserire i dati del nuovo contatto secondo il formato 'nome cognome numero telefonico'\n");
	char newContatto[100];
	scanf("%s", newContatto);
	char delimiter[] = " ";
	char* tokens = strtok(newContatto, delimiter);
	strcpy(array[contattoQta + 1].nome, tokens);
	tokens = strtok(NULL, delimiter);
	strcpy(array[contattoQta + 1].cognome, tokens);
	tokens = strtok(NULL, delimiter);
	strcpy(array[contattoQta + 1].numTelefono, tokens);
}

int SearchContatto(contatto_t array[], int contattoQta, char numTel[])
{
	for(int i = 0; i < contattoQta; i++)
	{
		if(strcmp(numTel, array[i].numTelefono) == 0)
		{
			return i;
		}
	}
}

void EliminateContatto(contatto_t array[], int *contattoQta)
{
	printf("Indicare il numero telefonico del contatto che vuoi eliminare.\n");
	char contattoNumTel[10];
	scanf("%s", contattoNumTel);
	int indexContatto = -1;
	indexContatto = SearchContatto(array, contattoQta, contattoNumTel);
	
	if(indexContatto != -1)
	{
		for(indexContatto; indexContatto < (*contattoQta) - 1; indexContatto++)
		{
			strcpy(array[indexContatto].nome, array[indexContatto + 1].nome);
			strcpy(array[indexContatto].cognome, array[indexContatto + 1].cognome);
			strcpy(array[indexContatto].numTelefono, array[indexContatto + 1].numTelefono);
		}
		(*contattoQta)--;
	}
	else
	{
		printf("Il contatto non esiste nella rubrica.\n");
	}
}

void Write(contatto_t array[], int contattoQta, char outputFileName[])
{
	FILE *outputFile = fopen(outputFileName, "w");
	for(int i = 0; i < contattoQta; i++)
	{
			fprintf(outputFile, "%s %s %s\n", array[i].nome, array[i].cognome, array[i].numTelefono);
	}
}

int main(int argc, char *argv[])
{
	contatto_t contatti[50];
	size_t size = sizeof contatti;
	
	if(argc == 2 || (argc == 4 && strcmp(argv[2], "-f") == 0))
	{
		int contattoQta = Load(contatti, size, argv[1]);
		
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
						ShowContatti(contatti, contattoQta);
						break;
					}
				case '2':
					{
						AddContatto(contatti, contattoQta);
						break;
					}
				case '3':
					{
						EliminateContatto(contatti, &contattoQta);
						break;
					}
				case '4':
					{
						if(argc == 2)
						{
							Write(contatti, contattoQta, argv[1]);
						}
						else
						{
							Write(contatti, contattoQta, argv[3]);
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
