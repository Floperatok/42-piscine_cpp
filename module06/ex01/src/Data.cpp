
#include "Data.hpp"


/* ########## Constructor ########## */

Data::Data(void) : _data("placeholder")
{
}

Data::Data(std::string str) : _data(str)
{
}

Data::Data(const Data &copy)
{
	if (&copy != this)
		*this = copy;
}

Data::~Data(void)
{
}


/* ########## Operator overload ########## */

Data &Data::operator=(const Data &other)
{
	if (&other != this)
	{
		this->_data = other._data;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */

const std::string	&Data::getData(void) const
{
	return (this->_data);
}


/* ########## Member function ########## */


/* ########## Exception ########## */


/* ########## Non-member function ########## */

