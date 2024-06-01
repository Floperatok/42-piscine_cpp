
#include "Cure.hpp"


/* ########## Constructor ########## */

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(const Cure &copy)
{
	if (&copy != this)
		*this = copy;
}

Cure::~Cure(void)
{
}


/* ########## Operator overload ########## */

Cure &Cure::operator=(const Cure &other)
{
	if (&other != this)
	{
		this->_type = other._type;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

Cure	*Cure::clone(void) const
{
	return (new Cure(*this));
}


/* ########## Non-member function ########## */

