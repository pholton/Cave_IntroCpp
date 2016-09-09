
#ifndef PERSON_H_
#define PERSON_H_

#include <iostream>
#include <string>

class Person {
private:
	std::string name;
	int age;
public:
	// Constructor Overloading
	// Constructor with no initial parameters
	Person();
	// Constructor that takes name parameter
	Person(std::string newName) { name = newName; age = 0; }; //can write function here, not limited to prototyping
	// Costsructor that takes name and age parameter
	Person(std::string newName, int newAge);

	std::string toString();
};
#endif