
#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <exception>
# include <sstream>
# include <fstream>
# include <limits>
# include <string>
# include <map>

class BitcoinExchange
{
private:
	std::map<std::string, std::string>	_baseData;
	std::map<std::string, std::string>	_toConvert;
	static const char					_delimBaseFile = ',';
	char								_delimInputFile;

	void		printResult(std::string &input) const;
	float		myStof(const std::string &s) const;
	std::string myStringTrim(const std::string &s, const char *charset) const;
	float	convert(const std::pair<std::string, std::string> line) const;
	std::string	readfile(const char *filename);
	bool		isDateValid(std::string s) const;
	void		testLine(const std::pair<std::string, std::string> &line) const;
	std::string	extractSubstring(std::string &s, char delim) const;
	std::pair<std::string, std::string>	parseLine(std::string line, char delim) const;
	std::map<std::string, std::string> parseFile(std::string filecontent, char delim);

public:
	BitcoinExchange(const char *filename, char delim);
	BitcoinExchange(const BitcoinExchange &copy);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	class CannotOpenFile : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class EmptyFile : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class DelimNotFound : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class InvalidNumber : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class InvalidDate : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class NotPositiveNumber : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class TooLargeNumber : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
	class MissingNumber : public std::exception
	{
	public:
		virtual const char	*what(void) const throw();
	};
};

void		printmap(const std::map<std::string, std::string> &m);

#endif
