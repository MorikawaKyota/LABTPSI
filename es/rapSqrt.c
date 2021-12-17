#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void main(int argc, char *argv[])
{
    double num1, num2, rapporto, radice;
    int checkNum = 0;

    do
    {
        printf("Inserire il primo numero reale.\n");
        scanf("%lf", &num1);
        printf("Inserire il secondo numero reale.\n");
        scanf("%lf", &num2);

        if(num1 >= num2 && num2 != 0)
        {
            rapporto = num1 / num2;
        }
        else if(num2 >= num1 && num1 != 0)
        {
            rapporto = num2 / num1;
        }
        else
        {
            printf("Impossibile dividere un numero per 0.\n");
            checkNum = -1;
            exit(0);
        }

        if(rapporto < 0)
        {
            printf("Impossibile eseguire l'estrazione della ridice di un numero negativo.\n");
            checkNum = -1;
        }
        else
        {
            radice = sqrt(rapporto);
            printf("La radice del rapporto dei due numeri inseriti è %lf.\n", radice);
        }
    }while(checkNum == 0);
}