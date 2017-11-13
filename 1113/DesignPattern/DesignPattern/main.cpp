#include "Singleton.h"
#include <stdio.h>

void func1()
{
	printf("Address : %p\n", Singleton1::Instance());
}

void func2()
{
	printf("Address : %p\n", Singleton2::Instance());
}

void main()
{
	Singleton1::Create();
	printf("Address : %p\n", Singleton1::Instance());
	func1();
	Singleton1::Delete();

	Singleton2::Instance();
	printf("Address : %p\n", Singleton2::Instance());
	func2();


	getchar();
}