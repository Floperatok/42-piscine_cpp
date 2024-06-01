
#include "IMateriaSource.hpp"


/* ########## Constructor ########## */

IMateriaSource::IMateriaSource(void)
{
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy)
{
	if (&copy != this)
		*this = copy;
}

IMateriaSource::~IMateriaSource(void)
{
}


/* ########## Operator overload ########## */

IMateriaSource &IMateriaSource::operator=(const IMateriaSource &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */


/* ########## Non-member function ########## */

