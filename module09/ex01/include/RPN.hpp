
#ifndef RPN_HPP
# define RPN_HPP

# include <stack>
# include <string>
# include <iostream>
# include <sstream>
# include <exception>

class RPN
{
private:
	std::stack<float>		_numbers;

	void	operate(const char operation);
	void	fillStack(const std::string &expr);
public:
	RPN(std::string expr);
	RPN(const RPN &copy);
	RPN &operator=(const RPN &other);
	~RPN(void);

	class NotValidCharacter : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class NotEnoughNumbers : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
	class NotEnoughOperators : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};
};

#endif
