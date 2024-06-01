
#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string _type;
public:
	AMateria(void);
    AMateria(std::string const &type);
    AMateria(const AMateria &copy);
    AMateria &operator=(const AMateria &other);
    virtual ~AMateria(void);

	std::string const	&getType(void) const;
	virtual AMateria	*clone(void) const = 0;
	virtual void		use(ICharacter &target);
};

#endif
