
#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main(void)
{
	try
	{
		std::cout << "vector : " << std::endl;
		std::vector<int>	vect;
		vect.push_back(78);
		vect.push_back(-43);
		vect.push_back(-30);
		vect.push_back(7);
		vect.push_back(16);
		std::cout << easyfind(vect, 78) << std::endl;
		std::cout << easyfind(vect, 44) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << std::endl;

	try
	{
		std::cout << "list : " << std::endl;
		std::list<int>	myList;
		myList.push_back(78);
		myList.push_back(-43);
		myList.push_back(-30);
		myList.push_back(7);
		myList.push_back(16);
		std::cout << easyfind(myList, 78) << std::endl;
		std::cout << easyfind(myList, 44) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	return (0);
}