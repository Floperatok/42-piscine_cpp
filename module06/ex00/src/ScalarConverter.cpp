
#include "ScalarConverter.hpp"


/* ########## Constructor ########## */

ScalarConverter::ScalarConverter(void)
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	if (&copy != this)
		*this = copy;
}

ScalarConverter::~ScalarConverter(void)
{
}


/* ########## Operator overload ########## */

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

bool	ScalarConverter::_isLiteral(const std::string &str)
{
	return (!str.compare("nan") 
		|| !str.compare("nanf") 
		|| !str.compare("-inff") 
		|| !str.compare("+inff") 
		|| !str.compare("-inf") 
		|| !str.compare("+inf"));
}

bool	ScalarConverter::_isChar(const std::string &str)
{
	if (str.length() > 1)
		return (false);
	if (std::isdigit(str.at(0)))
		return (false);
	return (true);
}

bool	ScalarConverter::_isText(const std::string &str)
{
	if (str.length() < 2)
		return (false);
	if (_isLiteral(str))
		return (false);
	if (!hasOnlyCharset(str, "+-0123456789.f"))
		return (true);
	int	dotCount = 0;
	for (int i = 0; i < (int)str.length(); i++)
	{
		if (str.at(i) == '.')
			dotCount++;
		if (i != 0 && (str.at(i) == '-' || str.at(i) == '+'))
			return (true);
		if (i != (int)str.length() - 1 && str.at(i) == 'f')
			return (true);
	}
	if (dotCount > 1)
		return (true);
	return (false);
}

char	ScalarConverter::_convertChar(std::string &str)
{
	double	d;
	char	val;

	if (_isChar(str))
		val = static_cast<char>(str.at(0));
	else
	{
		std::istringstream(str) >> d;
		if (_isLiteral(str))
			throw (Impossible());
		if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
			throw (OutOfBounds());
		val = static_cast<char>(d);
	}
	if (!std::isprint(val))
		throw (NonDisplayable());
	return (val);
}

int	ScalarConverter::_convertInt(std::string &str)
{
	double	d;
	int		val;

	if (_isChar(str))
		val = static_cast<int>(str.at(0));
	else
	{
		std::istringstream(str) >> d;
		if (_isLiteral(str))
			throw (Impossible());
		if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
			throw (OutOfBounds());
		val = static_cast<int>(d);
	}
	return (val);
}

float	ScalarConverter::_convertFloat(std::string &str)
{
	double	d;
	float	val;

	if (_isChar(str))
		val = static_cast<float>(str.at(0));
	else
	{
		d = std::atof(str.c_str());
		if (d < -std::numeric_limits<float>::max() 
			|| d > std::numeric_limits<float>::max())
			throw (OutOfBounds());
		val = static_cast<float>(d);
	}
	return (val);
}

double	ScalarConverter::_convertDouble(std::string &str)
{
	double	d;
	double	val;

	if (_isChar(str))
		val = static_cast<double>(str.at(0));
	else
	{
		d = std::atof(str.c_str());
		if (d < -std::numeric_limits<double>::max() 
			|| d > std::numeric_limits<double>::max())
			throw (OutOfBounds());
		val = static_cast<double>(d);
	}
	return (val);
}

void	ScalarConverter::_printChar(std::string &str)
{
	char	val;

	std::cout << "char:\t";
	try
	{
		val = _convertChar(str);
		std::cout << "'" << val << "'" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

void	ScalarConverter::_printInt(std::string &str)
{
	int	val;

	std::cout << "int:\t";
	try
	{
		val = _convertInt(str);
		std::cout << val << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

void	ScalarConverter::_printFloat(std::string &str)
{
	float	val;

	std::cout << "float:\t";
	try
	{
		val = _convertFloat(str);
		std::cout << val;
		if (val == (int)val)
			std::cout << ".0";
		std::cout << "f" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

void	ScalarConverter::_printDouble(std::string &str)
{
	double	val;

	std::cout << "double:\t";
	try
	{
		val = _convertDouble(str);
		std::cout << val;
		if (val == (int)val)
			std::cout << ".0";
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
}

void	ScalarConverter::convert(std::string str)
{
	if (str.length() == 0)
	{
		std::cerr << "Error: User input is empty." << std::endl;
		return ;
	}
	if (_isText(str))
	{
		std::cerr << "Error: User input format not recognized" << std::endl;
		return ;
	}
	_printChar(str);
	_printInt(str);
	_printFloat(str);
	_printDouble(str);
}


/* ########## Exception ########## */

const char	*ScalarConverter::NonDisplayable::what(void) const throw()
{
	return ("non displayable");
}

const char	*ScalarConverter::NotANumberFloat::what(void) const throw()
{
	return ("nanf");
}

const char	*ScalarConverter::NotANumberDouble::what(void) const throw()
{
	return ("nan");
}

const char *ScalarConverter::Impossible::what(void) const throw()
{
	return ("impossible");
}

const char *ScalarConverter::OutOfBounds::what(void) const throw()
{
	return ("out of bounds");
}


/* ########## Non-member function ########## */


bool	hasOnlyCharset(const std::string &str, const char *charset)
{
	for (int i = 0; i < (int)str.length(); i++)
		if (!std::strchr(charset, str.at(i)))
			return (false);
	return (true);
}