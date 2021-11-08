#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char argv[])
{
	char *names[] = {"Luca","Lorenzo","Davide", "Luca"};
	char *surnames[] = {"Montini","Canali","Fiorini", "Greggio"};
	int age[] = {22,24,24,26};
	int indexOldest = 0;
	
	for(int i = 0; i < 4; i++)
	{
		if(age[i + 1] >= age[i])
		{
			indexOldest = i;
		}
	}
	printf("%s\n", names[indexOldest]);
	return 0;
}
