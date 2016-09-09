// GettersAndSetters.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Person.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Person person;

	person.setName("Georgina");

	std::cout << person.toString() << std::endl;
	
	std::cout << "Name of Person with get method: " << person.getname() << std::endl;

	return 0;
}

