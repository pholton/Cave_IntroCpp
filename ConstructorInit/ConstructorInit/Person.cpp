#include "stdafx.h"
#include <iostream>
#include <sstream>
#include "Person.h"

std::string Person::toString() {
	std::stringstream ss;

	ss << "Name is: ";
	ss << name;
	ss << "; age is: ";
	ss << age;

	return ss.str();
}