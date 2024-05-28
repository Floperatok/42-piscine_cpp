
#include "Fixed.hpp"


/* ########## Constructor ########## */

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (&copy != this)
		*this = copy;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other != this)
	{
		this->_rawBits = other.getRawBits();
	}
	return (*this);
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


/* ########## Getter/Setter ########## */

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;\
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;\
	this->_rawBits = raw;
}