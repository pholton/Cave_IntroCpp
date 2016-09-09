// CopyConstructors.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

class Animal{
private:
	std::string name;

public:
	// Constructor
	Animal() { std::cout << "animal created." << std::endl; };
	// Copy Constructor
	Animal(const Animal &other): name(other.name){std::cout << "Animal created by copying." << std::endl; };
	void setName(std::string name) { this->name = name; };
	void speak() const { std::cout << "My name is: " << name << std::endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	// Invokes Constructor
	Animal animal1;
	animal1.setName("Freddy");

	// Invokes Copy Constructor
	Animal animal2 = animal1;
	// Animal 2 will say Freddy, since name is being passed with copy constructor
	animal2.speak();
	animal2.setName("Bob");

	// Freddy
	animal1.speak();
	// Bob
	animal2.speak();

	// Invokes Copy Constructor
	Animal animal3(animal1);
	// Freddy
	animal3.speak();

	return 0;
}

