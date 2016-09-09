// StaticVariables.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

// .h header file
class Test{
public:
	// Initialization of const must be done when it is created
	static int const MAX = 99;
private:
	int id;
	static int count;

public:
	Test() { id = ++count; }

	int getId() { return id; }

	static void showInfo() {
		std::cout << count << std::endl;
	}
};

// .cpp source
// static variables must be initialized somewhere, should be in .cpp
int Test::count = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	std::cout << Test::MAX << std::endl;

	Test test1;
	std::cout << "Object 1 ID: " << test1.getId() << std::endl;
	Test::showInfo();

	Test test2;
	std::cout << "Object 1 ID: " << test2.getId() << std::endl;
	Test::showInfo();

	return 0;
}

