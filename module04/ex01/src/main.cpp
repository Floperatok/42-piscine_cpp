
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	Animal	*animals[4];

	for (int i = 0; i < (int)(sizeof(animals) / sizeof(animals[0])); i++)
	{
		if (i < (int)(sizeof(animals) / sizeof(animals[0])) / 2)
			animals[i] = new Cat();
		else
			animals[i] = new Dog();
		std::cout << std::endl;
	}
	
	for (int i = 0; i < (int)(sizeof(animals) / sizeof(animals[0])); i++)
	{
		delete animals[i];
		std::cout << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	Dog basic;
	std::cout << std::endl;
	Dog tmp;
	std::cout << std::endl;
	tmp = basic;

	std::cout << std::endl;
	// you should make Dog::_brain public before removing following comments
	// std::cout << &basic._brain << std::endl;
	// std::cout << &tmp._brain << std::endl;
	std::cout << std::endl;
	
	return (0);
}
