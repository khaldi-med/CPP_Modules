#include "myClass.hpp"

myClass::myClass()
{
	std::cout << "Default constructor called" << std::endl;
}

myClass::~myClass()
{
	std::cout << "Destructor called" << std::endl;
}

myClass::myClass(int newAge, std::string newName) : age(newAge), name(newName)
{
	std::cout << "Constructor called" << std::endl;
}

void myClass::identify(void)
{
	std::cout << name << std::endl;
	std::cout << age << std::endl;
}

void myClass::setName(const std::string newName)
{
	this->name = newName;
}

void myClass::setAge(int newAge)
{
	age = newAge;
}

std::string myClass::getData(void)
{
  return " Age: " + std::to_string(age) + " Name: " + name;
}
