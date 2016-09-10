// ReverseString.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{

	char text[] = "Hello World!";

	int nChars = sizeof(text) - 1;
	
	// setup pointers to start and end of characters in text, excluding null terminator
	char *pStart = text;
	char *pEnd = text + nChars - 1;  // -1 excludes null terminator
	
	// Reverse characters using pointers in a for loop\
	// don't need initializer since pStart and pEnd are 
	// initialized above
	for (; pStart < pEnd; pStart++, pEnd--) {
		// store the "start" character in the temporary variable
		// *pStart dereferences the pointer
		char temp = *pStart;
		// assign "end" character to "start" character
		*pStart = *pEnd;
		// assign the character in temp (original "start") to "end" character
		*pEnd = temp;
	}
	std::cout << text << std::endl;

	// reset pointers to the start and end positions
	pStart = text;
	pEnd = text + nChars -  1;

	// Reverse characters using pointers in a while loop
	while (pStart < pEnd) {
		// store the "start" character in a temporary variable
		char temp = *pStart;
		// assign the character that the "end" pointer is pointing to 
		// to the "start" pointers character
		*pStart = *pEnd;
		// assign the character stored in temp to the "end" pointers character
		*pEnd = temp;
		
		// increment the "start" pointer and decrement the "end" pointer
		pStart++;
		pEnd--;
	}
	std::cout << text << std::endl;
	
	// Reverse characters using pointers in a for loop
	// same as above except variables are reinitialized in the declaration
	for (pStart = text, pEnd = text + nChars - 1; pStart < pEnd; pStart++, pEnd--) {
		char temp = *pStart;
		*pStart = *pEnd;
		*pEnd = temp;
	}
	std::cout << text << std::endl;

	// Bonus reverse with for loop, no pointers
	for (int i = sizeof(text) - 2, j = 0; i > j; i--, j++) {
		char temp = text[i];
		text[i] = text[j];
		text[j] = temp;
	}
	std::cout << text << std::endl;

	return 0;
}

