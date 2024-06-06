
#include "types.hpp"

void	identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Class: A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Class: B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Class: C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "Class: A" << std::endl;;
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "Class: B" << std::endl;;
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "Class: C" << std::endl;;
		return ;
	}
	catch(const std::exception& e)
	{
		(void)e;
	}
}