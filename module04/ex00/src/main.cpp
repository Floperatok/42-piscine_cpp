
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	const Animal *meta		= new Animal();
	const Animal *i			= new Cat();
	const Animal *j			= new Dog();
	const WrongAnimal *k	= new WrongCat();

	std::cout << std::endl;

	std::cout << i->getType() << " " << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << k->getType() << " " << std::endl;
	std::cout << meta->getType() << " " << std::endl;

	std::cout << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	delete k;
	return (0);
}
