#include <stdio.h>

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

	while (1);
}

