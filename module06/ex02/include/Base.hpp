
#ifndef BASE_HPP
# define BASE_HPP

class Base
{
private:
public:
	Base(void);
	Base(const Base &copy);
    Base &operator=(const Base &other);
	virtual ~Base(void);
};

#endif
