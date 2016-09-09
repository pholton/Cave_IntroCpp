// ConstuctorsAndInheritence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

class Machine{
private:
	int id;
public:
	Machine() { id = 0; std::cout << "Machine constructor, no arguments" << std::endl; }
	Machine(int id) : id(id) { std::cout << "Machine constructor, id set" << std::endl; }
	void info() { std::cout << "ID: " << id << std::endl; }
};

class Vehicle : public Machine {
public:
	Vehicle() { std::cout << "Vehicle constructor, no arguments" << std::endl; }
	Vehicle(int id) : Machine(id) { std::cout << "Vehicle construtor, id set" << std::endl; }
};

class Car : public Vehicle {
public:
	Car() { std::cout << "Car constructor, no arguments" << std::endl;}
	Car(int id) : Vehicle(id) { std::cout << "Car constructor, id set" << std::endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	Car car(42);
	car.info();

	return 0;
}

