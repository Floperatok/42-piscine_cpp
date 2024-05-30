
#include "WrongAnimal.hpp"


/* ########## Constructor ########## */

WrongAnimal::WrongAnimal(void) : _type("Some weird animal")
{
	std::cout << "WrongAnimal constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor" << std::endl;
}


/* ########## Operator overload ########## */

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal assignation overload" << std::endl;
	if (&other != this)
	{
		this->_type = other._type;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */

std::string	WrongAnimal::getType(void) const
{
	return (this->_type);
}


/* ########## Member function ########## */

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Some weird animal noise" << std::endl;
}


/* ########## Non-member function ########## */

