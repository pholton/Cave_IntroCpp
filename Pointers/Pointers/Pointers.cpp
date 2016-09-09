// Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void manipulate(int* value, int newValue);

int _tmain(int argc, _TCHAR* argv[])
{
	int value = 8;

	// &value returns the address that value is stored at.
	std::cout << "Value of value is: " << value << " and it is at memory address: " << &value << std::endl;

	// Create a pointer to an int
	int* pvalue;
	//points pvalue to the address of value
	pvalue = &value;

	// *pvalue dereferences the pointer pvalue, and returns the variable stored at the address pvalue points to.
	std::cout << "Value of pvalue is: " << *pvalue << " and it is at memory address: " << pvalue << std::endl;
	
	// Pass the manipulate function the address of value so the variable can be changed, not a copy
	manipulate(&value, 15);
	std::cout << "After manipulate" << std::endl;
	std::cout << "Value of value is: " << value << " and it is at memory address: " << &value << std::endl;
	std::cout << "Value of pvalue is: " << *pvalue << " and it is at memory address: " << pvalue << std::endl;

	// Pass the manipulate function the pointer pvalue, which points to the address that value is stored in
	manipulate(pvalue, 10);

	return 0;
}

// manipulate takes a pointer as an argument, so that a variable can be changed directly
void manipulate(int* value, int newValue) {
	std::cout << "Value is: " << *value << std::endl;
	// dereferences value and assigns the integer in newValue to the value variable
	*value = newValue;
	std::cout << "Value is: " << *value << std::endl;
}