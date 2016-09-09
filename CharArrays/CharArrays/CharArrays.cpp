// CharArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{

	char text[] = "hello";

	std::cout << text << std::endl;

	for (int i = 0; i < sizeof(text); i++) {
		std::cout << i << ": " << text[i] << std::endl;
	}

	int k = 0;
	while (text[k] != '\0') {
		std::cout << text[k] << std::flush;
		k++;
	}

	std::cout << std::endl;

	return 0;
}

