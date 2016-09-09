// multidimensionalArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	std::string animals[2][3] = { {"fox", "dog", "cat"}, {"mouse", "squirrel", "parrot"} };

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << animals[i][j] << " " << std::flush;
		}

		std::cout << std::endl;
	}
	*/
	int numbers[5][5] = { {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5}, {1,2,3,4,5} };

	std::cout << "   " << std::flush;
	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << " " << std::flush;
	}

	std::cout << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << i + 1 << "  " << std::flush;
		for (int j = 0; j < 5; j++) {
			std::cout << numbers[j][i] * numbers[i][j] << " " << std::flush;
		}
		std::cout << std::endl;
	}
	return 0;
}

