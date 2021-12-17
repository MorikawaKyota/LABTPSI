#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void PrintQuadrato(int N)
{
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			if(i!=0 && N-i!=1 && j!=0 && N-j!=1)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
		}
		printf("\n");	
	}
}

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("errore!\n");
	}
	else if(atoi(argv[1]) <= 0)
	{
		printf("errore!\n");
	}
	else
	{
		int n = atoi(argv[1]);
		PrintQuadrato(n);
	}
	
	return 0;
}
