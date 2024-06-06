
#include "Array.hpp"
#include <string>
#include <iostream>

int main(void)
{
	try
	{
		Array<int>	array(5);
		array[0] = 2;
		array[1] = 0;
		array[2] = 87;
		array[3] = -2;
		array[4] = 9772;
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;
		std::cout << array[3] << std::endl;
		std::cout << array[4] << std::endl;
		array[5] = 89;
		std::cout << array[5] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Array<std::string>	array(4);
		array[0] = "salut";
		array[1] = "je";
		array[2] = "suis";
		array[3] = "Nicolas!";
		std::cout << array[0] << std::endl;
		std::cout << array[1] << std::endl;
		std::cout << array[2] << std::endl;
		std::cout << array[3] << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		Array<int>	array;
		std::cout << array[0] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return (0);
}