
#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << this->_name << " created." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << " deleted." << std::endl;
}

void	Zombie::annonce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
