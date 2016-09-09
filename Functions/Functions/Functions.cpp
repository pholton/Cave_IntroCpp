// Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

void showMenu();
int getInput();
void processSelection(int choice);


int _tmain(int argc, _TCHAR* argv[])
{
	showMenu();
	int selection = getInput();
	processSelection(selection);


	return 0;
}

void showMenu() {
	std::cout << "1. Search" << std::endl;
	std::cout << "2. View Record" << std::endl;
	std::cout << "3. Quit" << std::endl;
}

int getInput() {
	std::cout << "Enter Selection: " << std::flush;

	int input;
	std::cin >> input;

	return input;
}

void processSelection(int choice) {
	switch (choice) {
	case 1:
		std::cout << "Searching..." << std::endl;
		break;
	case 2:
		std::cout << "Viewing..." << std::endl;
		break;
	case 3:
		std::cout << "Quitting..." << std::endl;
		break;
	default:
		std::cout << "Please Select an item from the menu" << std::endl;
	}
}