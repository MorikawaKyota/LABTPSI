#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
	int numAddendi, somma = 0;

	do
	{
		printf("Indicare quanti numeri vuoi inserire e calcolarne la media.\n");
		scanf("%d", &numAddendi);
	}while(numAddendi <= 0);

	for(int i = 0; i < numAddendi; i++)
	{
		int tmp = 0;
		printf("Inserire il %d esimo numero.\n", i);
		scanf("%d", &tmp);
		somma += tmp;
	}
	
	double media = (double) somma/numAddendi;
	
	printf("La media è %f", media);
	return 0;
}
