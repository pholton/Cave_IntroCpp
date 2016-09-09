// const.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Animal{
private:
	std::string name;

public:
	void setName(std::string name) { this->name = name; };
	// const prevents you from changing the instance variables (animal name) of the object
	void speak() const { std::cout << "My name is: " << name << std::endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{

	const double PI = 3.141592;
	std::cout << PI << std::endl;

	Animal animal;
	animal.setName("Freddy");
	animal.speak();

	int value = 8;
	// const int * const pValue = &value;
	int *pValue = &value;

	std::cout << *pValue << std::endl;

	int number = 11;
	pValue = &number; // Will throw an error with int * const pValue = &value;  Pointer is const
	*pValue = 12; // Will throw an error with: const int *pValue = &value;  Int is const
	// Both lines above would error out with: const int * const pValue = &value;  Int and pointer are const

	std::cout << *pValue << std::endl;

	return 0;
}

