#ifndef PERSON_H_
#define PERSON_H_

class Person{
private:
	std::string name;
	int age;

public:
	Person() { std::cout << "Person created." << std::endl; };

	Person(std::string name, int age) : name(name), age(age) { std::cout << "Person created." << std::endl; };

	Person(const Person &other) : name(other.name), age(other.age) { std::cout << "Person created by copy." << std::endl; };

	~Person() { std::cout << "Person destroyed." << std::endl; };

	void setName(std::string name) {
		this->name = name;
	};

	void setAge(int age) {
		this->age = age;
	};

	void speak() const {
		std::cout << "My name is " << name << std::endl;
	}
};

#endif