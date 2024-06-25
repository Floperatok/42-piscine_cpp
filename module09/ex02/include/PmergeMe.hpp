
#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <exception>
# include <string>
# include <cstdlib>
# include <cstring>
# include <iostream>
# include <algorithm>
# include <vector>
# include <iterator>

template <typename T>
class PmergeMe
{
private:
	char	**_args;
	T		_c;

	void	checkArgs(char **args) const;
	void	mergeInsertionSort(T &c);
public:
	PmergeMe(char **args);
	PmergeMe(const PmergeMe &copy);
	PmergeMe &operator=(const PmergeMe &other);
	~PmergeMe(void);

	unsigned long	getSize();
	void			load(void);
	void			sort(void);
	void			print(void) const;

	class InvalidNumber : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class DuplicateNumbers : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
};

/* ########## Constructor ########## */

template <typename T>
PmergeMe<T>::PmergeMe(char **args)
	: _args(args)
{
	checkArgs(this->_args);
}

template <typename T>
PmergeMe<T>::PmergeMe(const PmergeMe &copy)
{
	if (&copy != this)
		*this = copy;
}

template <typename T>
PmergeMe<T>::~PmergeMe(void)
{
}


/* ########## Operator overload ########## */

template <typename T>
PmergeMe<T> &PmergeMe<T>::operator=(const PmergeMe &other)
{
	if (&other != this)
	{
		this->_c = other._c;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

template <typename T>
void	PmergeMe<T>::checkArgs(char **args) const
{
	std::vector<char *>	tmp;
	for (int i = 0; args[i]; i++)
	{
		for (int j = 0; args[i][j]; j++)
		{
			if (!std::isdigit(args[i][j]))
				throw (InvalidNumber());
		}
		for (std::vector<char *>::const_iterator it = tmp.begin(); it != tmp.end(); it++)
			if (!std::strcmp(*it, args[i]))
				throw (DuplicateNumbers());
		tmp.push_back(args[i]);
	}
}

template <typename T>
unsigned long	PmergeMe<T>::getSize(void)
{
	return (this->_c.size());
}

template <typename T>
void	PmergeMe<T>::load(void)
{
	for (int i = 0; this->_args[i]; i++)
		this->_c.push_back(std::atoi(this->_args[i]));
}

template <typename T>
void	PmergeMe<T>::sort(void)
{
	mergeInsertionSort(this->_c);
}

template <typename T>
void	PmergeMe<T>::print(void) const
{
	int	i = 0;
	for (typename T::const_iterator it = this->_c.begin(); it != this->_c.end(); it++)
	{
		i++;
		if (i > 5)
		{
			std::cout << "[...]";
			break ;
		}
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	PmergeMe<T>::mergeInsertionSort(T &c)
{
	if (c.size() < 2)
		return ;
	if (c.size() == 2)
	{
		typename T::iterator	it = c.begin();
		typename T::iterator	jt = c.begin();
		jt++;
		if (*it > *jt)
		std::swap(*it, *jt);
	}
	typename T::iterator half = c.begin();
	std::advance(half, c.size() / 2);
	T	left(c.begin(), half);
	T	right(half, c.end());
	mergeInsertionSort(left);
	mergeInsertionSort(right);
	typename T::iterator it_left = left.begin();
	typename T::iterator it_right = right.begin();
	typename T::iterator it_c = c.begin();
	while (it_left != left.end() && it_right != right.end())
	{
		if (*it_left < *it_right)
			*(it_c++) = *(it_left++);
		else
			*(it_c++) = *(it_right++);
	}
	while (it_left != left.end())
		*(it_c++) = *(it_left++);
	while (it_right != right.end())
		*(it_c++) = *(it_right++);
}


/* ########## Exception ########## */

template <typename T>
const char	*PmergeMe<T>::InvalidNumber::what(void) const throw()
{
	return ("Exception: Invalid number");
}
template <typename T>
const char	*PmergeMe<T>::DuplicateNumbers::what(void) const throw()
{
	return ("Exception: Duplicate numbers");
}


#endif
