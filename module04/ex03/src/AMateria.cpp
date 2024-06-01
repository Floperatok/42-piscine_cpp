
#include "AMateria.hpp"


/* ########## Constructor ########## */

AMateria::AMateria(void) : _type("None")
{
}

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(const AMateria &copy)
{
	if (&copy != this)
		*this = copy;
}

AMateria::~AMateria(void)
{
}


/* ########## Operator overload ########## */

AMateria &AMateria::operator=(const AMateria &other)
{
	if (&other != this)
	{
		this->_type = other._type;	
	}
	return (*this);
}


/* ########## Setter/Getter ########## */

std::string const &AMateria::getType(void) const
{
	return (this->_type);
}


/* ########## Member function ########## */

void		AMateria::use(ICharacter &target)
{
	if (this->getType() == "ice")
	{
		std::cout << "* shoots an ice bolt at " \
		<< target.getName() << " *" << std::endl;
	}
	else if (this->getType() == "cure")
	{
		std::cout << "* heals " \
		<< target.getName() << "'s wounds *" << std::endl;
	}
}


/* ########## Non-member function ########## */

