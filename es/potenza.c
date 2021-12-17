#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        printf("errore!\n");
    }
    else if(atoi(argv[1]) < 0 || atoi(argv[2]) < 0)
    {
        printf("errore!\n");
    }
    else
    {
        int base = atoi(argv[1]);
        int esponente = atoi(argv[2]);
        int potenza = 1;
        for(int i = 0; i < esponente; i++)
        {
            potenza *= base;
        }
        printf("La potenza vale %d\n", potenza);
    }
    return 0;
}