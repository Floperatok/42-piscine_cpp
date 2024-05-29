
#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap a = ClapTrap();
	ClapTrap b = ClapTrap("bob");

	a.attack("bob");
	b.takeDamage(a.getAttackDamage());

	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);
	b.beRepaired(4);

	return (0);
}