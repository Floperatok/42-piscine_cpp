
#include "FragTrap.hpp"


/* ########## Constructor ########## */

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoint = 100;
	std::cout << "FragTrap '" << this->_name << "' constructor" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_attackDamage = 30;
	this->_energyPoint = 100;
	this->_hitPoint = 100;
	std::cout << "FragTrap '" << this->_name << "' constructor" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy)
{
	std::cout << "FragTrap copy constructor" << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap '" << this->_name << "' destructor" << std::endl;
}


/* ########## Operator overload ########## */

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "FragTrap assignment overload" << std::endl;
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a positive high five" << std::endl;
}


/* ########## Non-member function ########## */

