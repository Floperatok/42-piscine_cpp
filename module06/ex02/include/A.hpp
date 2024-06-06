
#ifndef A_HPP
# define A_HPP

# include "Base.hpp"

class A : public Base
{
private:
public:
    A(void);
    A(const A &copy);
    A &operator=(const A &other);
    ~A(void);
};

#endif
