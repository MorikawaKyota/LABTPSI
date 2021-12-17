#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, num3;
    int qtaPari = 0, qtaDispari = 0, qtaNull = 0;

    do
    {
        printf("Inserire il primo numero\n");
        scanf("%d", &num1);
        printf("Inserire il secondo numero\n");
        scanf("%d", &num2);
        printf("Inserire il terzo numero\n");
        scanf("%d", &num3);
        if(num1 - num2 == 0)
        {
            qtaNull++;
        }
        else if(((num1 - num2) % 2) == 0)
        {
            qtaPari++;
        }
        else
        {
            qtaDispari++;
        }
    }while((num1 + num2) > num3);
    printf("Le differenze tra il primo e il secondo numero sono state:\n%d pari\n%d dispari\n%d nulli\n", qtaPari,qtaDispari, qtaNull);
}