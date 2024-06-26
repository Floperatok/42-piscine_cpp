
#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>

class Cat : public Animal
{
private:
public:
    Cat(void);
    Cat(const Cat &copy);
    Cat &operator=(const Cat &other);
    ~Cat(void);

	void	makeSound(void) const;
};

#endif
