
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
private:
	std::string _name;

public:
	Zombie(void);
	~Zombie(void);

	void	setName(std::string name);
	void	annonce(void) const;
};

Zombie	*zombieHorde(int N, std::string name);

#endif
