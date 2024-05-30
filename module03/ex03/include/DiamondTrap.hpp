
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <string>
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;
	using FragTrap::_hitPoint;
	using FragTrap::_attackDamage;
	using ScavTrap::_energyPoint;
public:
    DiamondTrap(void);
	DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &copy);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap(void);

	using ScavTrap::attack;
	void	whoAmI(void);
};

#endif
