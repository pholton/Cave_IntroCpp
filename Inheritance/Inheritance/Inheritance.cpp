// Inheritance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Animal {
public:
	void speak() { std::cout << "Grrr" << std::endl; }
};

class Cat : public Animal {
public:
	void jump() { std::cout << "Cat jumping." << std::endl; }
	void speak() { std::cout << "Meow" << std::endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Animal a;
	a.speak();

	Cat cat;
	cat.speak();
	cat.jump();

	return 0;
}

