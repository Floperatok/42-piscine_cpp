
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template<typename T>
class Array
{
private:
	T 				*_array;
	unsigned int	_length;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &copy);
	Array	&operator=(const Array &toCopy);
	T		&operator[](const unsigned int i) const;

	unsigned int	size(void) const;

	class OutOfBound : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	~Array(void);
};

template<typename T>
Array<T>::Array(void) : _array(new T[0]), _length(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _length(n)
{
}

template<typename T>
Array<T>::Array(const Array &copy)
{
	if (&copy != this)
		*this = copy;
}

template<typename T>
Array<T>::~Array(void)
{
	delete [] this->_array;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array &other)
{
	if (&other != this)
	{
		this->_length = other._length;
		delete [] this->_array;
		this->_array = new T[other._length];
		for (unsigned int i = 0; i < this->_length; i++)
			this->_array[i] = other._array[i];
	}
	return (*this);
}

template<typename T>
T	&Array<T>::operator[](const unsigned int i)	const
{
	if (i >= this->_length)
		throw (Array<T>::OutOfBound());
	return (this->_array[i]);
}

template<typename T>
unsigned int	Array<T>::size(void) const
{
	return (this->_length);
}

template<typename T>
const char *Array<T>::OutOfBound::what(void) const throw()
{
	return ("Array: Exception error: Out of bounds");
}

#endif
