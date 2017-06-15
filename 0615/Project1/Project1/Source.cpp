#include <stdio.h>
#include <stdlib.h>

struct A
{
	char a;
	char b;
};

struct B
{
	int a;
	char b;
	char c;
};

struct C
{
	int a;
	char b;
	int c;
	char d;
	int e;
	char f;
};

void main()
{
	printf("A = %d\n", sizeof(A));
	printf("B = %d\n", sizeof(B));
	printf("C = %d\n", sizeof(C));


	int* Array;
	Array = (int*)malloc(sizeof(int) * 10);

	for (int i = 0; i < 10; i++)
	{
		Array[i] = i * 10;
		printf("Array[%d] = i", i, Array[i]);
	}


	int* Array2;
	Array2 = (int*)calloc(10, sizeof(int));

	for (int i = 0; i < 10; i++)
	{
		Array2[i] = i * 10;
		printf("Array[%d] = i", i, Array2[i]);
	}


	while (1);
}

