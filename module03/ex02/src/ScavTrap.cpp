
#include "ScavTrap.hpp"


/* ########## Constructor ########## */

ScavTrap::ScavTrap(void) : ClapTrap()
{
	this->_attackDamage = 20;
	this->_energyPoint = 50;
	this->_hitPoint = 100;
	std::cout << "ScavTrap '" << this->_name << "' constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_attackDamage = 20;
	this->_energyPoint = 50;
	this->_hitPoint = 100;
	std::cout << "ScavTrap '" << this->_name << "' constructor" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy) : ClapTrap(copy)
{
	std::cout << "ScavTrap copy constructor" << std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap '" << this->_name << "' destructor" << std::endl;
}


/* ########## Operator overload ########## */

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	ClapTrap::operator=(other);
	std::cout << "ScavTrap assignment overload" << std::endl;
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	ScavTrap::guardGate(void)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "Error: ScavTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ERROR: ScavTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		std::cout << "ERROR: ScavTrap " << this->_name << " is out of energy" << std::endl;
		return ;
	}
	this->_energyPoint--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target \
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}


/* ########## Non-member function ########## */

