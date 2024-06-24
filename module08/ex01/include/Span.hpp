
#ifndef SPAN_HPP
# define SPAN_HPP

# include <exception>
# include <vector>
# include <algorithm>
# include <cstdlib>
# include <iostream>

class Span
{
private:
	unsigned int _sizeMax;
	std::vector<int>_vect;
public:
	Span(void);
	Span(const unsigned int n);
	Span(const Span &copy);
	Span &operator=(const Span &other);
	~Span(void);

	void	addNumber(const int n);
	int		shortestSpan(void) const;
	int		longestSpan(void) const;
	void	addMultiple(int(*f)(void), unsigned int n);
	
	void	printSpan(void) const;
	void	printSpanSorted(void) const;

	class AlreadyFull : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class NotEnoughSpace : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class NotEnoughElements : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
};

#endif
