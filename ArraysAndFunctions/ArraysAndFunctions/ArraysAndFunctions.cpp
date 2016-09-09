// ArraysAndFunctions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

void show1(int nElements, std::string texts[]);
void show2(int nElements, std::string *texts);
void show3(std::string(&texts)[3]);
char *getMemory();
void freeMemory(char *pMem);

int _tmain(const int argc, _TCHAR* argv[])
{
	std::string texts[] = { "apple", "orange", "banana" };

	std::cout << sizeof(texts) << std::endl;

	show1(3, texts);
	show2(3, texts);
	show3(texts);

	char *pMemory = getMemory();
	freeMemory(pMemory);

	return 0;
}

// Pass in the array and number of elements
void show1(const int nElements, std::string texts[]) {
	// Cannot use sizeof inside of the function
	for (int i = 0; i < nElements; i++) {
		std::cout << texts[i] << std::endl;
	}
}

// Pass in a pointer to the array and the number of elements
void show2(const int nElements, std::string *texts) {
	// Cannot use sizeof inside the function
	for (int i = 0; i < nElements; i++) {
		std::cout << texts[i] << std::endl;
	}
}

// Pass in a reference to the array, reference and array must be in parenthesis in order to work
void show3(std::string(&texts)[3]) {
	// Can use sizeof inside of the function since we are using the reference to the original array, not a copy
	for (int i = 0; i < sizeof(texts) / sizeof(std::string); i++) {
		std::cout << texts[i] << std::endl;
	}
}

char *getMemory() {
	// Create new character pointer and allocate memory for the array
	char *pMem = new char[100];

	//  Return the character array
	return pMem;
}

void freeMemory(char *pMem) {
	// Deallocate memory of a char pointer
	delete[] pMem;
}