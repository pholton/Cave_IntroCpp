#include "stdafx.h"
#include <iostream>
#include "Cat.h"

using namespace cats;

Cat::Cat() {

}

Cat::~Cat() {

}

void Cat::speak() {
	std::cout << "Hisss!" << std::endl;
}