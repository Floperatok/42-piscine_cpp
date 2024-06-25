
#include "RPN.hpp"


/* ########## Constructor ########## */

RPN::RPN(std::string expr)
{
	try
	{
		fillStack(expr);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

RPN::RPN(const RPN &copy)
{
	if (&copy != this)
		*this = copy;
}

RPN::~RPN(void)
{
}


/* ########## Operator overload ########## */

RPN &RPN::operator=(const RPN &other)
{
	if (&other != this)
	{
		this->_numbers = other._numbers;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	RPN::operate(const char operation)
{
	float	tmp;
	float	tmp2;

	if (this->_numbers.size() < 2)
		throw (NotEnoughNumbers());
	tmp = this->_numbers.top();
	this->_numbers.pop();
	tmp2 = this->_numbers.top();
	this->_numbers.pop();
	switch (operation)
	{
	case '+':
		this->_numbers.push(tmp2 + tmp);
		break;
	case '-':
		this->_numbers.push(tmp2 - tmp);
		break;
	case '*':
		this->_numbers.push(tmp2 * tmp);
		break;
	case '/':
		this->_numbers.push(tmp2 / tmp);
		break;
	default:
		break;
	}
}

void	RPN::fillStack(const std::string &expr)
{
	std::istringstream sstream(expr);
	std::string character;

	while (sstream)
	{
		sstream >> character;
		if (!sstream)
			break ;
		if (character.size() != 1 || character.find_first_not_of("0123456789/*-+") != std::string::npos)
			throw (NotValidCharacter());
		if (character.find_first_not_of("0123456789") == std::string::npos)
			this->_numbers.push(character.at(0) - '0');
		else
			operate(character.at(0));
	}
	if (this->_numbers.size() > 1)
		throw (NotEnoughOperators());
	std::cout << this->_numbers.top() << std::endl;
}


/* ########## Exception ########## */

const char	*RPN::NotValidCharacter::what(void) const throw()
{
	return ("Exception: Character isn't valid");
}
const char	*RPN::NotEnoughNumbers::what(void) const throw()
{
	return ("Exception: Not Enough Numbers");
}
const char	*RPN::NotEnoughOperators::what(void) const throw()
{
	return ("Exception: Not enough operators");
}


/* ########## Non-member function ########## */
