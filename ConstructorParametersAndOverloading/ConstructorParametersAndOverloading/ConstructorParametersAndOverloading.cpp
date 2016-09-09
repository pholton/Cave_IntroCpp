// ConstructorParametersAndOverloading.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Person person1;
	Person person2("Bob");
	Person person3("Sue", 35);

	std::cout << person1.toString() << std::endl;
	std::cout << person2.toString() << std::endl;
	std::cout << person3.toString() << std::endl;

	return 0;
}

