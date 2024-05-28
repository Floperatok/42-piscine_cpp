
#include "Fixed.hpp"
#include <cmath>


/* ########## Constructor ########## */

Fixed::Fixed(void) : _rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int rawBits) : _rawBits(rawBits << Fixed::_nb_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float rawBits) : _rawBits(roundf(rawBits * (1 << Fixed::_nb_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &copy)
{
	std::cout << "Copy constructor called" << std::endl;
	if (&copy != this)
		*this = copy;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}


/* ########## Operator overload ########## */

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other != this)
	{
		this->_rawBits = other._rawBits;
	}
	return (*this);
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


/* ########## Public method ########## */

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << Fixed::_nb_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_nb_bits);
}


/* ########## Function ########## */

std::ostream &operator<<(std::ostream &stream, const Fixed &other)
{
	stream << other.toFloat();
	return (stream);
}
