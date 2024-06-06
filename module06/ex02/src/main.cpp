
#include "types.hpp"

int main(void)
{
	Base *p = generate();
	std::cout << "pointer identification:\t\t";
	identify(p);
	std::cout << "reference identification:\t";
	identify(*p);
	
	delete p;

	return (0);
}