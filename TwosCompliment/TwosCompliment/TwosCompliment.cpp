// TwosCompliment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

int _tmain(int argc, _TCHAR* argv[])
{
	char value = 127;

	std::cout << (int)value << std::endl;

	value++;

	std::cout << (int)value << std::endl;

	return 0;
}

