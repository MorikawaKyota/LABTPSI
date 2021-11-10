#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
	{
		char name[50];
		char surname[100];
		int age;
	}student_t;
	
void ArrayInitialize(student_t array[], size_t size)
{
	char *names[] = {"Luca","Lorenzo","Davide", "Luca"};
	char *surnames[] = {"Montini","Canali","Fiorini", "Greggio"};
	int age[] = {22,24,24,26};
	for(int i = 0; i < size / sizeof(array[0]); i++)
	{
		strcpy(array[i].name, names[i]);
		strcpy(array[i].surname, surnames[i]);
		array[i].age = age[i];
		printf("%d\n", i);
	}
}

int AgeCompare(student_t array[], size_t size)
{
	int indexOldest = 0;
	for(int i = 0; i < size / sizeof(array[0]) - 1; i++)
		{
			if(array[i + 1].age >= array[i].age)
				{
					indexOldest = i + 1;
				}
		}
	return indexOldest;
}

int main(int argc, char argv[])
{
	int indexOldest = 0;
	student_t students[4];
	size_t arrSize = sizeof students;
	
	ArrayInitialize(students, arrSize);
	indexOldest = AgeCompare(students, arrSize);
	
	printf("%s is the oldest.\n", students[indexOldest].name);
	return 0;
}
