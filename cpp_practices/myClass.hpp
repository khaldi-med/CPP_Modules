#ifndef MYCLASS_HPP
#define MYCLASS_HPP

#include <iostream>
#include <string>

class myClass
{
private:
	int age;
	std::string name;
public:
	myClass();
	myClass(int age, std::string name);

	void identify(void);
	void  setAge(int age);
	void  setName(const std::string name );
  std::string getData(void);
	~myClass();
};

#endif
