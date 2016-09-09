// StringStreams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>

int _tmain(int argc, _TCHAR* argv[])
{

	std::string name = "Bob";
	int age = 32;

	std::stringstream ss;

	ss << "Name is: ";
	ss << name;
	ss << "; Age is: ";
	ss << age;

	std::string info = ss.str();

	std::cout << info << std::endl;

	return 0;
}

