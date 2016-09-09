// DoWhile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{

	const std::string password = "password";
	std::string input;

	do {
		std::cout << "Enter your password: " << std::flush;
		std::cin >> input;

		if (input == password) {
			break;
		}
	} while (true);

	std::cout << "Access Granted." << std::endl;

	return 0;
}

