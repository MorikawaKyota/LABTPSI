#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ArrayPopolazione(int numArray[], int arraySize)
{
	printf("Adesso inserisci i numeri.\n");
	
	int i;
	for(i = 0; i<arraySize; i++)
	{
		scanf("%d", &numArray[i]);
	}
}

int Ricerca(int numArray[], int numCercato, int arraySize)
{
	int frequenza = 0, i;
	for(i = 0; i<arraySize; i++)
	{
		if(numArray[i] == numCercato)
		{
			frequenza++;
		}
	}
	return frequenza;
}

int main()
{
	int qtaNum;
	printf("Indicare quanti numeri vuoi inserire.\n");	
	scanf("%d", &qtaNum);
	
	int numeri[qtaNum];
	ArrayPopolazione(numeri, qtaNum);
	
	printf("Indicare il numero di cui vuoi calcolare la frequenza.\n");
	int numCercato;
	scanf("%d", &numCercato);
	
	int frequenza = Ricerca(numeri, numCercato, qtaNum);
	
	if(frequenza != 0)
	{
		printf("Il numero %d viene inserito %d volte.\n", numCercato, frequenza);
	}
	else
	{
		printf("Non hai mai inserito il numero %d nell'array.\n", numCercato);
	}
	return 0;
}
