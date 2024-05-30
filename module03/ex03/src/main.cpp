
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

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
	std::cout << "\n";
	
	FragTrap c("leo");

	c.attack("default");
	a.takeDamage(c.getAttackDamage());

	std::cout << "\n";

	c.highFivesGuys();
	
	std::cout << "\n";
	std::cout << "\n";

	DiamondTrap d("niko");
	d.whoAmI();

	std::cout << "\n";

	a.attack("niko");
	d.takeDamage(a.getAttackDamage());

	d.attack("default");
	a.takeDamage(d.getAttackDamage());

	std::cout << "\n";

	return (0);
}