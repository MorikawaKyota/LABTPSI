#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void Count(int *frequenza, char letter, char word[])
{
	for(int i = 0; i<50; i++)
	{
		if(word[i] == letter)
		{
			*frequenza= *frequenza+1;		
		}	
	}
}

void AcquisizioneEConto(int *frequenza)
{
	char parola[50];
	char letteraRicercata;
	
	printf("Indicare la lettera di cui vuoi sapere la frequenza di comparsa.\n");
	letteraRicercata= getchar();
	
	printf("Inserire la parola.\n");
	scanf("%s", parola);
	
	Count(frequenza, letteraRicercata, parola);
}

int main()
{
	int numComparsa=0;
	AcquisizioneEConto(&numComparsa);
	
	printf("La lettera ricercata è comparsa %d volte.\n", numComparsa);
	return 0;
}
