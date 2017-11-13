#include "Singleton.h"
#include <stdio.h>

void func1()
{
	printf("Address : %p\n", Singleton<NEW_CREATE>::Instance());
}

void func2()
{
	printf("Address : %p\n", Singleton<LOCAL_STATIC_VALUE>::Instance());
}

void main()
{
	Singleton<NEW_CREATE>::Create();
	printf("Address : %p\n", Singleton<NEW_CREATE>::Instance());
	func1();
	Singleton<NEW_CREATE>::Delete();

	Singleton<LOCAL_STATIC_VALUE>::Instance();
	func2();


	getchar();
}