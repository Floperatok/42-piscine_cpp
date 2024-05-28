
#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed	ab	= (a.getX() - point.getX()) * (b.getY() - point.getY()) 
				- (a.getY() - point.getY()) * (b.getX() - point.getX());
	Fixed	bc	= (b.getX() - point.getX()) * (c.getY() - point.getY()) 
				- (a.getY() - point.getY()) * (c.getX() - point.getX());
	Fixed	ac	= (c.getX() - point.getX()) * (a.getY() - point.getY()) 
				- (c.getY() - point.getY()) * (a.getX() - point.getX());
	
	return ((ab > 0 && bc > 0 && ac > 0) || (ab < 0 && bc < 0 && ac < 0));
}
