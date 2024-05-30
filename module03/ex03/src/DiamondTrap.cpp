
#include "DiamondTrap.hpp"


/* ########## Constructor ########## */

DiamondTrap::DiamondTrap(void) : ClapTrap(), _name("default")
{
	std::cout << "DiamondTrap " << this->_name << " Constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"), _name(name)
{
	std::cout << "DiamondTrap '" << this->_name << "' Constructor " << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy) : ClapTrap(copy)
{
	std::cout << "DiamondTrap copy constructor" << std::endl;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap '" << this->_name << "' destructor" << std::endl;
}


/* ########## Operator overload ########## */

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "DiamondTrap assignment overload" << std::endl;
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap name : " << this->_name << 
		" ; Parent ClapTrap name : " << ClapTrap::_name << std::endl;
}


/* ########## Non-member function ########## */

