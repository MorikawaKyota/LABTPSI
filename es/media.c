#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int limA, limB,somNumInseriti = 0, qtaNumInseriti= 0, checkNum = 0;
    double media;
    printf("Inserire il numero A\n");
    scanf("%d", &limA);

    printf("Inserire il numero B\n");
    scanf("%d", &limB);

    int num;
    do
    {
    printf("Inserire un numero\n");
    scanf("%d", &num);
    qtaNumInseriti++;
    somNumInseriti += num;

    if(limA >= limB)
    {
        if(num < limB || num >limA)
        {
            checkNum = -1;
        }
    }
    else if(num < limA || num >limB)
    {
        checkNum = -1;
    }
    }while(checkNum == 0);
    media = (double) somNumInseriti / (double)qtaNumInseriti;
    printf("La media dei valori inseriti è %lf\n", media);
}