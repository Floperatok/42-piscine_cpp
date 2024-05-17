
#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombies = zombieHorde(5, "uwu");

	for (int i = 0; i < 5; i++)
	{
		zombies[i].annonce();
	}
	
	delete [] zombies;
	return (0);
}
