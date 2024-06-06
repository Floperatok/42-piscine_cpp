
#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <string>
# include <cstdlib>
# include <exception>
# include <sstream>
# include <cstring>
# include <limits>
# include <iostream>

class ScalarConverter
{
private:
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter &copy);
    ScalarConverter &operator=(const ScalarConverter &other);
    ~ScalarConverter(void);

	static bool	_isLiteral(const std::string &str);
	static bool	_isChar(const std::string &str);
	static bool	_isText(const std::string &str);

	static char		_convertChar(std::string &str);
	static int		_convertInt(std::string &str);
	static float	_convertFloat(std::string &str);
	static double	_convertDouble(std::string &str);

	static void	_printChar(std::string &str);
	static void	_printInt(std::string &str);
	static void	_printFloat(std::string &str);
	static void	_printDouble(std::string &str);

	class NonDisplayable : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class NotANumberFloat : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class NotANumberDouble : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class Impossible : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};
	class OutOfBounds : public std::exception
	{
		public:
			virtual const char	*what(void) const throw();
	};

public:
	static void	convert(std::string str);
};

bool	hasOnlyCharset(const std::string &str, const char *charset);

#endif
