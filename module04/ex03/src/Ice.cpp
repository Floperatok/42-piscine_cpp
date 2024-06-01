
#include "Ice.hpp"


/* ########## Constructor ########## */

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(const Ice &copy)
{
	if (&copy != this)
		*this = copy;
}

Ice::~Ice(void)
{
}


/* ########## Operator overload ########## */

Ice &Ice::operator=(const Ice &other)
{
	if (&other != this)
	{
		this->_type = other._type;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

Ice	*Ice::clone(void) const
{
	return (new Ice(*this));
}


/* ########## Non-member function ########## */

