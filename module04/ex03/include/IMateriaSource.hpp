
#ifndef IMATERIASOURCE_HPP
# define IMATERIASOURCE_HPP

# include "AMateria.hpp"
# include <string>

class IMateriaSource
{
private:
public:
    IMateriaSource(void);
    IMateriaSource(const IMateriaSource &copy);
    IMateriaSource &operator=(const IMateriaSource &other);
    virtual	~IMateriaSource(void);

	virtual void		learnMateria(AMateria*) = 0;
	virtual AMateria	*createMateria(std::string const & type) = 0;
};

#endif
