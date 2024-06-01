
#ifndef ICE_HPP
# define ICE_HPP

# include <string>
# include "AMateria.hpp"

class Ice : public AMateria
{
private:
public:
    Ice(void);
    Ice(const Ice &copy);
    Ice &operator=(const Ice &other);
    ~Ice(void);

	Ice	*clone(void) const;
};

#endif
