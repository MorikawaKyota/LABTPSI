#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void PopolazioneArray(int *numeri, int qtaNum)
{
	printf("Adesso inserisci i numeri.\n");
	for(int i=0; i<qtaNum; i++)ù
	{
		cin >> numeri[i];
	}
}

int CalcoloMax(int *numeri, int qtaNum)
{
	int max = numeri[0];
	for(int i=1; i<qtaNum; i++)
	{
		if(numeri[i] > max)
		{
			max=numeri[i];
		}
	}
	return max;
}

int CalcoloMin(int *numeri, int qtaNum)
{
	int min = numeri[0];
	for(int i=1; i<qtaNum; i++)
	{
		if(numeri[i]<min)
		{
			min=numeri[i];
		}
	}
	return min;
}

int main()
{
	int qtaNum;
	do
	{
		printf("Indicare la quantità di numeri da inserire di cui vuoi trovare il massimo ed il minimo.\n");
	}while(qtaNum<=0);

	int numeri [qtaNum];

	PopolazioneArray(int *numeri,int qtaNum);
	int max = CalcoloMax(int *numeri, int qtaNum);
	int min = CalcoloMin(int *numeri, int qtaNum);

	printf("Il minimo e il massimo dei numeri inseriti sono rispettivamente %d è %d.\n", min, max);
	return 0;
}
