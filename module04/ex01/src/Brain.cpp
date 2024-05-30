
#include "Brain.hpp"


/* ########## Constructor ########## */

Brain::Brain(void)
{
	std::cout << "Brain constructor" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor" << std::endl;
}


/* ########## Operator overload ########## */

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain assignation overload" << std::endl;
	if (&other != this)
	{
		for (int i = 0; i < 100; i++)
		{
			this->_ideas[i] = other._ideas[i];
		}
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */


/* ########## Non-member function ########## */

