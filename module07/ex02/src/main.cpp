
#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
	Array<int>	array(10);

	array[0] = 2;
	std::cout << array[0] << std::endl;
	return (0);
}