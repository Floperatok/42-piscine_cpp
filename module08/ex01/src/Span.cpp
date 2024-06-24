
#include "Span.hpp"


/* ########## Constructor ########## */

Span::Span(void) : _sizeMax(0)
{
}

Span::Span(const unsigned int n) : _sizeMax(n)
{
}

Span::Span(const Span &copy)
{
	if (&copy != this)
		*this = copy;
}

Span::~Span(void)
{
}


/* ########## Operator overload ########## */

Span &Span::operator=(const Span &other)
{
	if (&other != this)
	{
		this->_sizeMax = other._sizeMax;
		this->_vect = other._vect;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	Span::addNumber(const int n)
{
	if (this->_vect.size() == this->_sizeMax)
		throw (AlreadyFull());
	this->_vect.push_back(n);
}

void	Span::addMultiple(int(*f)(void), unsigned int n)
{
	if (this->_vect.size() + n > this->_sizeMax)
		throw (NotEnoughSpace());
	for (unsigned int i = 0; i < n; i++)
		this->_vect.push_back(f());
}

int	Span::shortestSpan(void) const
{
	if (this->_vect.size() < 2)
		throw (NotEnoughElements());
	std::vector<int> sortedVect = this->_vect;
	std::sort(sortedVect.begin(), sortedVect.end());
	int	min = abs(sortedVect[0] - sortedVect[1]);
	for (std::vector<int>::iterator it = sortedVect.begin() + 1; it != sortedVect.end(); it++)
	{
		if (abs(*it - *(it - 1)) < min)
			min = abs(*it - *(it - 1));
	}
	return (min);
}

int	Span::longestSpan(void) const
{
	if (this->_vect.size() < 2)
		throw (NotEnoughElements());
	std::vector<int> sortedVect = this->_vect;
	std::sort(sortedVect.begin(), sortedVect.end());
	return (abs(*sortedVect.begin() - *(sortedVect.end() - 1)));
}

void	Span::printSpan(void) const
{
	for (std::vector<int>::const_iterator it = this->_vect.begin(); it != this->_vect.end(); it++)
		std::cout << *it << "\n";
	std::cout << std::flush;
}

void	Span::printSpanSorted(void) const
{
	std::vector<int> sortedVect = this->_vect;
	std::sort(sortedVect.begin(), sortedVect.end());
	for (std::vector<int>::const_iterator it = sortedVect.begin(); it != sortedVect.end(); it++)
		std::cout << *it << "\n";
	std::cout << std::flush;
}


/* ########## Exception ########## */

const char	*Span::AlreadyFull::what(void) const throw()
{
	return ("Span: Exception: Span's already full");
}

const char	*Span::NotEnoughSpace::what(void) const throw()
{
	return ("Span: Exception: Not enough space");
}

const char	*Span::NotEnoughElements::what(void) const throw()
{
	return ("Span: Exception: Not enough elements");
}


/* ########## Non-member function ########## */
