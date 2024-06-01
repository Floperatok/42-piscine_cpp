
#include "Character.hpp"


/* ########## Constructor ########## */

Character::Character(void) : _name("default_name")
{
	for (int i = 0; i < 4; i++)
		this->_inv[i] = 0;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i < 4; i++)
		this->_inv[i] = 0;
}

Character::Character(const Character &copy)
{
	if (&copy != this)
	{
		for (int i = 0; i < 4; i++)
			this->_inv[i] = 0;
		*this = copy;
	}
}

Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_inv[i])
			delete this->_inv[i];
	}
}


/* ########## Operator overload ########## */

Character &Character::operator=(const Character &other)
{
	if (&other != this)
	{
		this->_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (this->_inv[i])
			{
				delete this->_inv[i];
				this->_inv[i] = 0;
			}
			if (other._inv[i])
				this->_inv[i] = other._inv[i]->clone();
		}
	}
	return (*this);
}


/* ########## Setter/Getter ########## */

const std::string	&Character::getName(void) const
{
	return (this->_name);
}

AMateria	*Character::getInv(int idx) const
{
	if (idx >= 0 && idx < 4)
		return (this->_inv[idx]);
	return (0);
}


/* ########## Member function ########## */

void	Character::equip(AMateria *m)
{
	int	i = 0;

	while (i != 4 && this->_inv[i] != 0)
		i++;
	if (i != 4)
		this->_inv[i] = m;
}

void	Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4)
		this->_inv[idx] = 0;
}

void	Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx < 4 && this->_inv[idx] != 0)
		this->_inv[idx]->use(target);
}


/* ########## Non-member function ########## */

