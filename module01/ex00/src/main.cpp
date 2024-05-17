
#include "Zombie.hpp"

int main(void)
{
	Zombie	*zombie = newZombie("allocedZombie");

	zombie->annonce();
	randomChump("stackedZombie");
	delete zombie;
	return (0);
}
