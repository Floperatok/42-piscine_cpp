
#include "ClapTrap.hpp"


/* ########## Constructor ########## */

ClapTrap::ClapTrap(void) : _name("default"), _hitPoint(100), _energyPoint(50), _attackDamage(20)
{
	std::cout << "ClapTrap '" << this->_name << "' constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(100), _energyPoint(50), _attackDamage(20)
{
	std::cout << "ClapTrap '" << this->_name << "' constructor" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
	std::cout << "ClapTrap copy constructor" << std::endl;
	if (&copy != this)
		*this = copy;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap '" << this->_name << "' destructor" << std::endl;
}

	
/* ########## Operator overload ########## */

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap assignment overload" << std::endl;
	if (&other != this)
	{
		this->_name = other._name;
		this->_hitPoint = other._hitPoint;
		this->_energyPoint = other._energyPoint;
		this->_attackDamage = other._attackDamage;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */

int	ClapTrap::getAttackDamage(void) const
{
	return (this->_attackDamage);
}


/* ########## Member function ########## */

void	ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ERROR: ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		std::cout << "ERROR: ClapTrap " << this->_name << " is out of energy" << std::endl;
		return ;
	}
	this->_energyPoint--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target \
		<< ", causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ERROR: ClapTrap " << this->_name << " is already dead" << std::endl;
		return ;
	}
	this->_hitPoint -= amount;
	std::cout << "ClapTrap " << this->_name << " took " << amount \
		<< " points of damage!" << std::endl;
	if (this->_hitPoint <= 0)
		std::cout << "ClapTrap " << this->_name << " died." << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoint <= 0)
	{
		std::cout << "ERROR: ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
	if (this->_energyPoint <= 0)
	{
		std::cout << "ERROR: ClapTrap " << this->_name << " is out of energy" << std::endl;
		return ;
	}
	this->_energyPoint--;
	this->_hitPoint += amount;
	std::cout << "ClapTrap " << this->_name << " heals for " << amount << \
		" points for a total of " << this->_hitPoint << " PV!" << std::endl;
}


/* ########## Non-member function ########## */

