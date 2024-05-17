
#include <string>
#include <iostream>

int main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*pStr = &str;
	std::string	&rStr = str;

	std::cout << &str << std::endl;
	std::cout << pStr << std::endl;
	std::cout << &rStr << std::endl;

	std::cout << str << std::endl;
	std::cout << *pStr << std::endl;
	std::cout << rStr << std::endl;
	
	return (0);
}
