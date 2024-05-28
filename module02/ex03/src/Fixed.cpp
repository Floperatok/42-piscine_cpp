
#include "Fixed.hpp"
#include <cmath>


/* ########## Constructor ########## */

Fixed::Fixed(void) : _rawBits(0)
{
}

Fixed::Fixed(const int rawBits) : _rawBits(rawBits << Fixed::_nb_bits)
{
}

Fixed::Fixed(const float rawBits) : _rawBits(roundf(rawBits * (1 << Fixed::_nb_bits)))
{
}

Fixed::Fixed(const Fixed &copy)
{
	if (&copy != this)
		*this = copy;
}

Fixed::~Fixed(void)
{
}


/* ########## Operator overload ########## */

Fixed &Fixed::operator=(const Fixed &other)
{
	if (&other != this)
	{
		this->_rawBits = other._rawBits;
	}
	return (*this);
}

bool	Fixed::operator>(const Fixed &other) { return (this->_rawBits > other._rawBits); }
bool	Fixed::operator<(const Fixed &other) { return (this->_rawBits < other._rawBits); }
bool	Fixed::operator>=(const Fixed &other) { return (this->_rawBits >= other._rawBits); }
bool	Fixed::operator<=(const Fixed &other) { return (this->_rawBits <= other._rawBits); }
bool	Fixed::operator==(const Fixed &other) { return (this->_rawBits == other._rawBits); }
bool	Fixed::operator!=(const Fixed &other) { return (this->_rawBits != other._rawBits); }
Fixed	Fixed::operator+(const Fixed &other) { return (Fixed(this->toFloat() + other.toFloat())); }
Fixed	Fixed::operator-(const Fixed &other) { return (Fixed(this->toFloat() - other.toFloat())); }
Fixed	Fixed::operator*(const Fixed &other) { return (Fixed(this->toFloat() * other.toFloat())); }
Fixed	Fixed::operator/(const Fixed &other) { return (Fixed(this->toFloat() / other.toFloat())); }
Fixed	&Fixed::operator++(void) { this->_rawBits++; return (*this); }
Fixed	&Fixed::operator--(void) { this->_rawBits--; return (*this); }
Fixed	Fixed::operator++(int) { Fixed tmp(this->toFloat()); this->_rawBits++; return (tmp); }
Fixed	Fixed::operator--(int) { Fixed tmp(this->toFloat()); this->_rawBits--; return (tmp); }


/* ########## Getter/Setter ########## */

int	Fixed::getRawBits(void) const
{
	return (this->_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	this->_rawBits = raw;
}


/* ########## Member function ########## */

float	Fixed::toFloat(void) const
{
	return ((float)this->_rawBits / (1 << Fixed::_nb_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_rawBits >> Fixed::_nb_bits);
}

Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	if (a._rawBits < b._rawBits)
		return (a);
	return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a._rawBits < b._rawBits)
		return (a);
	return (b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	if (a._rawBits > b._rawBits)
		return (a);
	return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a._rawBits > b._rawBits)
		return (a);
	return (b);
}


/* ########## Non-member function ########## */

std::ostream &operator<<(std::ostream &stream, const Fixed &other)
{
	stream << other.toFloat();
	return (stream);
}
