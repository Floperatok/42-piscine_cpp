
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <string>
# include <iostream>

class ScavTrap : public ClapTrap
{
private:
public:
    ScavTrap(void);
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &copy);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap(void);

	void	guardGate(void);
	void	attack(const std::string &target);
};

#endif
