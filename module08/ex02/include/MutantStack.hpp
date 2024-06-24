
#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
public:
	MutantStack(void);
	MutantStack(const MutantStack &copy);
	MutantStack &operator=(const MutantStack &other);
	~MutantStack(void);

	typedef typename	std::stack<T>::container_type::iterator			iterator;
	typedef typename	std::stack<T>::container_type::const_iterator	const_iterator;

	iterator	begin(void);
	iterator	end(void);
	const_iterator	begin(void) const;
	const_iterator	end(void) const;
};

/* ########## Constructor ########## */
template <typename T>
MutantStack<T>::MutantStack(void)
{
}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy)
{
	if (&copy != this)
		*this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
}


/* ########## Operator overload ########## */
template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->c.end());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::begin(void) const
{
	return (this->c.begin());
}

template <typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::end(void) const
{
	return (this->c.end());
}


/* ########## Exception ########## */


/* ########## Non-member function ########## */


#endif
