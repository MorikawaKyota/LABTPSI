#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void OutPutting(char outputFileName[], int frequence, char searchedWord[], char flag[])
{
	FILE *outputFile = fopen(outputFileName, "w");
	if(frequence == 0)
	{
		fprintf(outputFile, "La ricerca non ha prodotto risultati.\n");
	}
	else if(flag == "-c")
	{
		fprintf(outputFile, "La lettera %s comapre %d volte.\n", searchedWord, frequence);
	}
	else
	{
		fprintf(outputFile, "La parola %s comapre %d volte.\n", searchedWord, frequence);
	}
}

int SearchString(char inputFileName[], char searchedWord[])
{
	int count = 0;
	FILE *inputFile = fopen(inputFileName, "r");
	char line[100];
	
	while(fscanf(inputFile, "%s", line) == 1)
	{
		if(strstr(line, searchedWord) != 0)
		{
			count++;
		}
	}
	return count;
}

int SearchChar(char inputFileName[], char searchedChar[])
{
	int count = 0;
	FILE *inputFile = fopen(inputFileName, "r");
	char line[100];
	
	while(fscanf(inputFile, "%s", line) == 1)
	{
		if(strstr(line, searchedChar) != 0)
		{
			count++;
		}
	}
	return count;
}

int main(int argc, char *argv[])
{
	int frequenza = 0;

	if(strcmp(argv[3], "-c") == 0)
	{
		if(strlen(argv[4]) == 1)
		{
			frequenza = SearchChar(argv[1], argv[4]);
			OutPutting(argv[2], frequenza, argv[4], argv[3]);
		}
		else
		{
			printf("Hai inserito troppe lettere.\n");
		}
	}
	else if(strcmp(argv[3], "-p") == 0)
	{
		frequenza = SearchString(argv[1], argv[4]);
		OutPutting(argv[2], frequenza, argv[4], argv[3]);
	}
	else
	{
		printf("Invalid option\n");
	}
	return 0;
}
