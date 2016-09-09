// NewOperator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Animal{
private:
	std::string name;

public:
	// Constructor
	Animal() {
		std::cout << "Animal created." << std::endl;
	}

	// Copy constructor
	Animal(const Animal &other) : name(other.name) {
		std::cout << "Animal created by copying." << std::endl;
	}

	// Destructor
	~Animal() {
		std::cout << "Destructor called." << std::endl; 
	}

	// setName method, assign name to object
	void setName(std::string name) {
		this->name = name;
	}

	// speak method, say the objects name
	void speak() const {
		std::cout << "My name is: " << name << std::endl;
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	// Allocate memory for new Animal object
	Animal *pCat1 = new Animal();
	
	// Call methods on pointer objects using the -> symbol
	pCat1->setName("Freddy");
	pCat1->speak();

	// Free the memory that was used by pCat1 object
	delete pCat1;

	return 0;
}

