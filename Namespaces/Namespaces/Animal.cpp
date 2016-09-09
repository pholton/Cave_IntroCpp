#include "stdafx.h"
#include <iostream>
#include "Animal.h"

using namespace ani;

Cat::Cat() {
}

Cat::~Cat() {

}

void Cat::speak() {
	std::cout << "Meow" << std::endl;
}