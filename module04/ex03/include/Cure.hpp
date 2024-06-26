
#ifndef CURE_HPP
# define CURE_HPP

# include <string>
# include "AMateria.hpp"

class Cure : public AMateria
{
private:
public:
    Cure(void);
    Cure(const Cure &copy);
    Cure &operator=(const Cure &other);
    ~Cure(void);

	Cure	*clone(void) const;
};

#endif
