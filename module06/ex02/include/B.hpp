
#ifndef B_HPP
# define B_HPP

# include "Base.hpp"

class B : public Base
{
private:
public:
    B(void);
    B(const B &copy);
    B &operator=(const B &other);
    ~B(void);
};

#endif
