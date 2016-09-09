#include "stdafx.h"
#include <iostream>
#include <string>
#include "Person.h"


Person::Person() {
	name = "George";
}


Person::~Person() {
}

std::string Person::toString() {
	return "Person's name is " + name;
}

// Set method
void Person::setName(std::string newName) {
	name = newName;
}

// Get method
std::string Person::getname() {
	return name;
}