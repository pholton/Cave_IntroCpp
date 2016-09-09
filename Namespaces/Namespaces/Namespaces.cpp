// Namespaces.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Cat.h"
#include "Animal.h"

int _tmain(int argc, _TCHAR* argv[])
{
	ani::Cat cat1;
	cat1.speak();

	cats::Cat cat2;
	cat2.speak();

	std::cout << cats::CATNAME << std::endl;
	std::cout << ani::CATNAME << std::endl;

	return 0;
}

