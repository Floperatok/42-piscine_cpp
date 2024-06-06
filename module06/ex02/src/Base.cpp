
#include "Base.hpp"


/* ########## Constructor ########## */

Base::Base(void)
{
}

Base::Base(const Base &copy)
{
	if (&copy != this)
		*this = copy;
}

Base::~Base(void)
{
}


/* ########## Operator overload ########## */

Base &Base::operator=(const Base &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */


/* ########## Exception ########## */


/* ########## Non-member function ########## */

