
#include "MateriaSource.hpp"


/* ########## Constructor ########## */

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = 0;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	if (&copy != this)
	{
		for (int i = 0; i < 4; i++)
			this->_materia[i] = 0;
		*this = copy;
	}
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		delete this->_materia[i];
}


/* ########## Operator overload ########## */

MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	if (&other != this)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i])
			{
				delete this->_materia[i];
				this->_materia[i] = 0;
			}
			if (other._materia[i])
				this->_materia[i] = other._materia[i]->clone();
		}
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	MateriaSource::learnMateria(AMateria *m)
{
	int	i = 0;

	while (i != 4 && this->_materia[i])
		i++;
	if (i != 4)
		this->_materia[i] = m;
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	int	i = 0;

	while (i < 4 && this->_materia[i])
	{
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
		i++;
	}
	return (0);
}	


/* ########## Non-member function ########## */

