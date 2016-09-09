// AllocatingMemory.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"


Person *createPeople(int numPeople);
void namePeople(Person *pPerson, int numPeople);
void freePeople(Person *pPeople);

int _tmain(int argc, _TCHAR* argv[])
{
	/*
	Person *pPerson = new Person[26];

	char c = 'a';
	
	for ( int i = 0; i < 26; i++, c++) {
		std::string name(1, c);
		pPerson[i].setName(name);
		pPerson[i].speak();
	}

	delete [] pPerson;
	*/

	const int NUMPEOPLE = 26;

	Person *pPerson = createPeople(NUMPEOPLE);

	namePeople(pPerson, NUMPEOPLE);

	freePeople(pPerson);

	return 0;
}

// Create new Person pointer object
Person *createPeople(int numPeople) {
	Person *pPerson = new Person[numPeople];
	return pPerson;
}

// Name people in person pointer object
void namePeople(Person *pPerson, int numPeople) {
	char c = 'a';

	for (int i = 0; i < numPeople; i++, c++) {
		std::string name(1, c);
		pPerson[i].setName(name);
		pPerson[i].speak();
	}
}

// Delete person pointer object
void freePeople(Person *pPeople) {
	delete[] pPeople;
}