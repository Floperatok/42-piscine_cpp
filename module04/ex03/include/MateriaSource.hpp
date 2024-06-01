
#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include <string>
# include "IMateriaSource.hpp"
# include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
private:
	AMateria	*_materia[4];
public:
    MateriaSource(void);
    MateriaSource(const MateriaSource &copy);
    MateriaSource &operator=(const MateriaSource &other);
    ~MateriaSource(void);

	AMateria	*createMateria(std::string const &type);
	void		learnMateria(AMateria *materia);
};

#endif
