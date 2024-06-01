
#include "ICharacter.hpp"


/* ########## Constructor ########## */

ICharacter::ICharacter(void)
{
}

ICharacter::ICharacter(const ICharacter &copy)
{
	if (&copy != this)
		*this = copy;
}

ICharacter::~ICharacter(void)
{
}


/* ########## Operator overload ########## */

ICharacter &ICharacter::operator=(const ICharacter &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */


/* ########## Non-member function ########## */

