#include "myClass.hpp"

int main()
{
	myClass obj;
	obj.setName("John");
	obj.setAge(30);
	obj.identify();
  std::cout << obj.getData() << std::endl;
	return 0;
}
