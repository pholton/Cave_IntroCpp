#ifndef Person_H_
#define Person_H_

#include <iostream>
#include <string>

class Person {
private:
	std::string name;
public:
	Person();
	~Person();
	std::string toString();
	void setName(std::string newName);
	std::string getname();
};

#endif
