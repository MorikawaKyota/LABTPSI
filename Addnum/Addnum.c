#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool controllo(int num)
{
	bool isPositive=false;
	if(num>0)
	{
		isPositive=true;
	}
	return isPositive;
}

int somma(int num1,int num2)
{
	int somma = num1 + num2;
	return somma;
}

int main()
{
	int add1, add2;
	do
	{
		printf("Inserire il primo addendo.\n");
		scanf("%d", &add1);
	}while(controllo(add1)==false);

	do
	{
		printf("Inserire il secondo addendo.\n");
		scanf("%d", &add2);
	}while(controllo(add2)==false);

	int risultato=somma(add1, add2);
	printf("Il risultato della somma= %d. \n", risultato);
	return 0;
}
