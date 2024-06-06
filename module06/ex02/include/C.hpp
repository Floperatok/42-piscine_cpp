
#ifndef C_HPP
# define C_HPP

# include "Base.hpp"

class C : public Base
{
private:
public:
    C(void);
    C(const C &copy);
    C &operator=(const C &other);
    ~C(void);
};

#endif
