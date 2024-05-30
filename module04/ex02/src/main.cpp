
#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "Dog.hpp"
#include <iostream>

int main(void)
{
	// Animal *a = new Animal();
	Animal *b = new Cat();

	b->makeSound();

	delete b;

	return (0);
}
