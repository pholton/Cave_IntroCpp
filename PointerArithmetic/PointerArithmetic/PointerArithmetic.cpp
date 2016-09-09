// PointerArithmetic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{

	const int NSTRINGS = 5;
	std::string texts[NSTRINGS] = { "one", "two", "three", "four", "five" };

	std::string *pTexts = texts;

	pTexts += 3;

	std::cout << *pTexts << std::endl;

	pTexts -= 2;

	std::cout << *pTexts << std::endl << std::endl;

	std::string *pEnd = &texts[NSTRINGS];
	pTexts = texts;

	while (pTexts != pEnd) {
		std::cout << *pTexts << std::endl;
		pTexts++;
	}

	// Reset pTexts
	pTexts = texts;
	// Get number of elements using pointer arithmetic, cast to long not required, added for clairity
	long elements = long(pEnd - pTexts);

	std::cout << elements << std::endl;

	// Reset pTexts
	pTexts = texts;
	pTexts += NSTRINGS / 2;

	std::cout << *pTexts << std::endl;

	return 0;
}

