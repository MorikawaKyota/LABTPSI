#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Controllo(int argc, char flag[])
{
    if(argc != 6 || strcmp("-s", flag) != 0)
    {
        printf("Errore!\n");
        exit;
    }
}

int Load(char fileName[], char contenuto[100][100])
{
    FILE *inputFile = fopen(fileName, "r");
    int charQta = 0;
    while(!feof(inputFile))
    {
        fscanf(inputFile, "%s", contenuto[charQta]);
        charQta++;
    }
    fclose(inputFile);
    return charQta;
}

void Sostituzione(char charDaSostituire,char charSostituente, char testo[100][100], int charQta)
{
    for(int i = 0; i < charQta; i++)
    {
        for(int j = 0; j<100; j++)
        {
            if(testo[i][j] == charDaSostituire)
            {
                testo[i][j] = charSostituente;
            }
        }

    }
}

void Scrittura(char fileName[], char testo[100][100], int charNumber)
{
    FILE *outputFile = fopen(fileName, "w");
    for(int i = 0; i < charNumber - 1; i++)
    {
        fprintf(outputFile, "%s ", testo[i]);
    }
    fclose(outputFile);
    printf("Modificato\n");
}

int main(int argc, char *argv[])
{
    Controllo(argc, argv[3]);
    char contenuto[100][100];
    int n = Load(argv[1], contenuto);
    Sostituzione(argv[4][0], argv[5][0], contenuto, n);
    Scrittura(argv[2], contenuto, n);
    return 0;
}