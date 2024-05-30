
#include "WrongCat.hpp"


/* ########## Constructor ########## */

WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << "WrongCat constructor" << std::endl;
	this->_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &copy)
{
	std::cout << "WrongCat copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor" << std::endl;
}


/* ########## Operator overload ########## */

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat assignation overload" << std::endl;
	if (&other != this)
	{
		this->_type = other._type;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	WrongCat::makeSound(void) const
{
	std::cout << "*weom weom*" << std::endl;
}


/* ########## Non-member function ########## */

