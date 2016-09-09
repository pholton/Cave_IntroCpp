// ConstructorsAndDestructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Cat.h"

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << "Starting program..." << std::endl;

	// We can force the object to be destroyed before the program finishes by putting
	// the instanciation inside of curly brackets (limit it's scope)
	{
		Cat bob;
		bob.speak();
	}

	std::cout << "Ending program..." << std::endl;

	return 0;
}

