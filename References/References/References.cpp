// References.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// value is passed in by reference, so the value of the variable
// that is passed in is actually changed, similar to passing a 
// pointer to the function
void changeSomething(double &value);

int _tmain(int argc, _TCHAR* argv[])
{
	int value1 = 8;
	int &value2 = value1;
	value2 = 10;

	std::cout << "Value 1: " << value1 << std::endl;
	std::cout << "Value 2: " << value2 << std::endl;

	double value = 4.321;
	changeSomething(value);

	std::cout << value << std::endl;

	return 0;
}

void changeSomething(double &value) {
	value = 123.4;
}