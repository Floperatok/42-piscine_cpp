
#include "Dog.hpp"


/* ########## Constructor ########## */

Dog::Dog(void) : Animal()
{
	std::cout << "Dog constructor" << std::endl;
	this->_brain = new Brain();
	this->_type = "Dog";
}

Dog::Dog(const Dog &copy)
{
	std::cout << "Dog copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

Dog::~Dog(void)
{
	delete this->_brain;
	std::cout << "Dog destructor" << std::endl;
}


/* ########## Operator overload ########## */

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog assignation overload" << std::endl;
	if (&other != this)
	{
		this->_type = other._type;	
		delete this->_brain;
		this->_brain = new Brain(*other._brain);
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	Dog::makeSound(void) const
{
	std::cout << "*woof!*" << std::endl;
}


/* ########## Non-member function ########## */

