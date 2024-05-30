
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>

class WrongCat : public WrongAnimal
{
private:
public:
    WrongCat(void);
    WrongCat(const WrongCat &copy);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat(void);

	void	makeSound(void) const;
};

#endif
