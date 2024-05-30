
#include "Cat.hpp"


/* ########## Constructor ########## */

Cat::Cat(void) : Animal()
{
	std::cout << "Cat constructor" << std::endl;
	this->_brain = new Brain();
	this->_type = "Cat";
}

Cat::Cat(const Cat &copy)
{
	std::cout << "Cat copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

Cat::~Cat(void)
{
	delete this->_brain;
	std::cout << "Cat destructor" << std::endl;
}


/* ########## Operator overload ########## */

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat assignation overload" << std::endl;
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

void	Cat::makeSound(void) const
{
	std::cout << "*meow meow*" << std::endl;
}


/* ########## Non-member function ########## */

