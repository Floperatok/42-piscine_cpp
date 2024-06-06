
#include "Serializer.hpp"


/* ########## Constructor ########## */

Serializer::Serializer(void)
{
}

Serializer::Serializer(const Serializer &copy)
{
	if (&copy != this)
		*this = copy;
}

Serializer::~Serializer(void)
{
}


/* ########## Operator overload ########## */

Serializer &Serializer::operator=(const Serializer &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

uintptr_t	Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}



/* ########## Exception ########## */


/* ########## Non-member function ########## */

