// ReturningObjects.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Animal{
private:
	std::string name;

public:
	Animal() { std::cout << "Animal created." << std::endl; };

	Animal(std::string name) : name(name) {};

	Animal(const Animal &other) : name(other.name) {};

	~Animal() { std::cout << "Animal destroyed." << std::endl; };

	void setName(std::string name) {
		this->name = name;
	};
	
	void sayName() { 
		std::cout << "My name is " << name << std::endl; 
	}
	
};

Animal* createAnimal() {
	Animal *pAnimal = new Animal();
	pAnimal->setName("Stevie");
	return pAnimal;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Animal *pCat = createAnimal();

	pCat->sayName();

	delete pCat;

	return 0;
}

