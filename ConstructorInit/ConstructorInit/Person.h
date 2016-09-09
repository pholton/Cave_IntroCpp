
#ifndef PERSON_H_
#define PERSON_H_

#include <string>

class Person{
private:
	std::string name;
	int age;

public:
	Person() : name("unnamed"), age(0) {};
	Person(std::string name, int age) : name(name), age(age) {};
	std::string toString();
};

#endif