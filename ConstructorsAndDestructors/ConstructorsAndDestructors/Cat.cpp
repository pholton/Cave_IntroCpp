
#include "stdafx.h"
#include <iostream>
#include "Cat.h"

// Constructor
Cat::Cat() {
	std::cout << "Cat created" << std::endl;

	//initialize property inside of the constructor
	happy = true;
}

// Destructor
Cat::~Cat() {
	std::cout << "Cat destroyed" << std::endl;
}

// speak method
void Cat::speak() {
	if (happy){
		std::cout << "Meoww!" << std::endl;
	}
	else {
		std::cout << "Hisss!" << std::endl;
	}
}