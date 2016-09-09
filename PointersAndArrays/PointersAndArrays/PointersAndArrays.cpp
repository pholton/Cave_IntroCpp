// PointersAndArrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

int _tmain(int argc, _TCHAR* argv[])
{
	std::string texts[] = { "one", "two", "three" };

	std::string *pTexts = texts;

	std::cout << sizeof(texts) / sizeof(std::string) << std::endl;

	std::cout << "Access Elements using standard array notation" << std::endl;
	for (int i = 0; i < sizeof(texts) / sizeof(std::string); i++) {
		std::cout << texts[i] << " " << std::flush;
	}

	std::cout << std::endl << "Access Elements using pointer to array (*pTexts)" << std::endl;

	for (int i = 0; i < sizeof(texts) / sizeof(std::string); i++, pTexts++) {
		std::cout << *pTexts << " " << std::flush;
	}

	std::string *pElement = texts; // or &texts[0]
	std::string *pEnd = &texts[(sizeof(texts)/sizeof(std::string))-1]; // or &texts[2]

	/*
	while (true) {
		std::cout << *pElement << " " << std::flush;

		if (pElement == pEnd) {
			break;
		}

		pElement++;
	}
	*/
	
	std::cout << std::endl << "Access Elements using pElements" << std::endl;

	for (pElement; pElement <= pEnd; pElement++) {
		std::cout << *pElement << " " << std::flush;
	}

	std::cout << std::endl;

	return 0;
}