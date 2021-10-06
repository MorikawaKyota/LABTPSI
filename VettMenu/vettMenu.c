#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void PopolazioneArray(int numeri[], int qtaNum)
{
	int i;
	for(i=0; i<qtaNum; i++)
	{
		scanf("%d", &numeri[i]);
	}
}

void StampaArrayInv(int array[], int size)
{
	int i;
	for(i=size-1; i >= 0; i--)
	{
		printf("%d\n", array[i]);
	}
}

void StampaArray(int array[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		printf("%d\n", array[i]);
	}
}

void StampaPari(int array[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(array[i]%2 == 0)
		{
			printf("%d\n", array[i]);
		}
	}
}

void StampaDispari(int array[], int size)
{
	int i;
	for(i=0; i<size; i++)
	{
		if(array[i]%2 == 1)
		{
			printf("%d\n", array[i]);
		}
	}
}

bool Ricerca(int array[], int **size, int numCercato)
{
	int i;
	bool result = false;
	for(int i=0; i < **size; i++)
	{
		if(array[i]==numCercato)
		{
			result = true;
			break;
		}

	}
	
	return result;
}

void RicercaNum(int array[], int *size)
{
	printf("Indicare il numero che vuoi cercare.\n");
	int numCercato;
	scanf("%d", &numCercato);
	if(Ricerca(array, &size, numCercato) == true)
	{
		printf("Il numero ricercato esiste nell'array.\n");
	}
		else
	{
		printf("Il numero che vuoi eliminare non esiste nell'array.\n");
	}
}

void EliminaNum(int array[], int *size)
{
	printf("Indicare il numero che vuoi eliminare.\n");
	int numCercato;
	scanf("%d", &numCercato);
	if(Ricerca(array, &size, numCercato)==true)
	{
		printf("Il numero che vuoi eliminare esiste nell'array.\n");
		int i, index;
		for(i=0; i < *size; i++)
		{
			if(array[i] == numCercato);
			{
				index = i;
				break;
			}
		}
		
		for(i; i < *size -1; i++)
		{
			array[i] = array[i+1];
		}
		*size --;
		printf("Numero eliminato dall'array.\n");
	}
	else
	{
		printf("Il numero che vuoi eliminare non esiste nell'array.\n");
	}
}

void ScambioDue(int array[], int size)
{
	int i = 0;
	for(i;size-i != 0 && size-i != 1; i += 2)
	{
		int tmp=array[i];
		array[i] = array[i+1];
		array[i+1] = tmp;
	}
}

void OrdinareArray(int array[], int size)
{
	int scelta;
	printf("1 ordine crescente\n2 ordine decrescente\n");
	scanf("%d", &scelta);
	
	switch(scelta)
	{
		case 1:
		{
			int arrayIndex = 0,
			swapIndex = 0;
			for(arrayIndex; arrayIndex < size-1; arrayIndex++)
			{
				for(swapIndex = arrayIndex + 1; swapIndex < size; swapIndex++)
				{
					if(array[swapIndex] < array[arrayIndex])
					{
						int tmp=array[arrayIndex];
						array[arrayIndex] = array[swapIndex];
						array[swapIndex] = tmp;	
					}
				}
			}
			printf("Array ordinato.\n");
			break;
		}
		case 2:
		{
			int arrayIndex = 0,
			swapIndex = 0;
			for(arrayIndex; arrayIndex < size-1; arrayIndex++)
			{
				for(swapIndex = arrayIndex + 1; swapIndex < size; swapIndex++)
				{
					if(array[swapIndex] > array[arrayIndex])
					{
						int tmp=array[arrayIndex];
						array[arrayIndex] = array[swapIndex];
						array[swapIndex] = tmp;	
					}
				}
			}
			printf("Array ordinato.\n");
			break;
		}
		default:
			printf("opzione invalida.\n");
			break;
	}
}
int main()
{
	int size;
	printf("Indicare la lunghezza del vettore.\n");
	scanf("%d", &size);
	
	int numeri [size];
	printf("Adesso inserire i numeri nel vettore.\n");
	PopolazioneArray(numeri, size);

	bool exit= false;
	do
	{
		int scelta=0;
		printf("Menu di gestione di un vettore:\n");
		printf("1 stampa elementi vettore\n");
		printf("2 stampa inversa elementi vettore\n");
		printf("3 stampa tutti i numeri pari\n");
		printf("4 stampa tutti i numeri dispari\n");
		printf("5 ricerca numero nell'array\n");
		printf("6 eliminare un elemento dall'array, se esistente\n");
		printf("7 scambiare a due a due le posizioni del vettore\n");
		printf("8 ordinare il vettore\n");
		printf("9 exit\n");
		
		scanf("%d", &scelta);
		switch(scelta)
		{
			case 1:
				StampaArray(numeri, size);
				break;
			case 2:
				StampaArrayInv(numeri, size);
				break;
			case 3:
				StampaPari(numeri, size);
				break;
			case 4:
				StampaDispari(numeri, size);
				break;
			case 5:
				RicercaNum(numeri, &size);
				break;
			case 6:
				EliminaNum(numeri, &size);
				break;
			case 7:
				ScambioDue(numeri, size);
				break;
			case 8:
				OrdinareArray(numeri, size);
				break;
			case 9:
				exit=true;
				break;
			default:
				printf("opzione invalida.\n");
				break;
		}
	}while(exit==false);
	
	return 0;
}
