
#include "Point.hpp"


/* ########## Constructor ########## */

Point::Point(void) : _x(0), _y(0)
{
}

Point::Point(float x, float y) : _x(x), _y(y)
{
}

Point::Point(const Point &copy)
{
	if (&copy != this)
		*this = copy;
}

Point::~Point(void)
{
}

/* ########## Operator overload ########## */

Point &Point::operator=(const Point &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}

/* ########## Setter/Getter ########## */

Fixed	Point::getX(void) const
{
	return (this->_x);
}

Fixed	Point::getY(void) const
{
	return (this->_y);
}


/* ########## Member function ########## */


/* ########## Non-member function ########## */

