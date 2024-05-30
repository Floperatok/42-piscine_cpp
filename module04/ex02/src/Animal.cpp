
#include "Animal.hpp"


/* ########## Constructor ########## */

Animal::Animal(void) : _type("Some unknow animal")
{
	std::cout << "Animal constructor" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor" << std::endl;
}


/* ########## Operator overload ########## */

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignation overload" << std::endl;
	if (&other != this)
	{
		this->_type = other._type;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */

std::string	Animal::getType(void) const
{
	return (this->_type);
}


/* ########## Member function ########## */


/* ########## Non-member function ########## */

