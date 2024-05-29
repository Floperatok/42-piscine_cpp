
#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap a;
	ScavTrap b("bob");

	std::cout << "\n";

	a.attack("bob");
	b.takeDamage(a.getAttackDamage());

	std::cout << "\n";

	b.guardGate();
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);

	std::cout << "\n";
	
	a.attack("bob");
	b.takeDamage(a.getAttackDamage());
	a.attack("bob");
	b.takeDamage(a.getAttackDamage());
	a.attack("bob");
	b.takeDamage(a.getAttackDamage());
	a.attack("bob");
	b.takeDamage(a.getAttackDamage());
	a.attack("bob");
	b.takeDamage(a.getAttackDamage());

	std::cout << "\n";
	
	ScavTrap c;
	c = b;

	std::cout << "\n";

	return (0);
}