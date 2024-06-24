
#include "BitcoinExchange.hpp"


/* ########## Constructor ########## */

BitcoinExchange::BitcoinExchange(const char *filename, char delimInputFile)
{
	this->_delimInputFile = delimInputFile;
	try
	{
		std::string buf;
		
		buf = readfile("data.csv");
		this->_baseData = parseFile(buf, this->_delimBaseFile);
		buf = readfile(filename);
		printResult(buf);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy)
{
	if (&copy != this)
		*this = copy;
}

BitcoinExchange::~BitcoinExchange(void)
{
}


/* ########## Operator overload ########## */

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (&other != this)
	{
		this->_baseData = other._baseData;
		this->_toConvert = other._toConvert;
		this->_delimInputFile = other._delimInputFile;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

float	BitcoinExchange::myStof(const std::string &s) const
{
	std::istringstream	iss(s);
	float	res;
	iss >> res;
	return (res);
}

float	BitcoinExchange::convert(const std::pair<std::string, std::string> line) const
{
	std::map<std::string, std::string>::const_iterator	it = this->_baseData.lower_bound(line.first);
	
	if (it == this->_baseData.end() || (it->first != line.first && it != this->_baseData.begin()))
		it--;
	return (myStof(line.second) * myStof(it->second));
}

std::string BitcoinExchange::myStringTrim(const std::string &s, const char *charset) const
{
	unsigned long first = s.find_first_not_of(charset);
	unsigned long last = s.find_last_not_of(charset);
	if (first == std::string::npos || last == std::string::npos)
		return (std::string());
	return (s.substr(first, last - first + 1));
}

std::string	BitcoinExchange::readfile(const char *filename)
{
	std::multimap<std::string, float>	m;
	std::ifstream					file;
	std::string						filecontent;

	file.open(filename);
	if (!file.is_open())
		throw (CannotOpenFile());
	std::getline(file, filecontent, '\0');
	if (filecontent.empty())
		throw (EmptyFile());
	file.close();
	return (filecontent);
}

/*
 *	Returns substring of s between 0 and delim. Deletes from s the said substring
*/
std::string	BitcoinExchange::extractSubstring(std::string &s, char delim) const
{
	unsigned long	delimPos = s.find(delim);
	std::string		substring;

	if (delimPos == std::string::npos)
	{
		substring = s.substr();
		s.erase();
		return (substring);
	}
	substring = s.substr(0, delimPos);
	s.erase(0, delimPos + 1);
	return (substring);
}

bool	BitcoinExchange::isDateValid(std::string s) const
{
	const char	*allowedChars = "0123456789";
	std::string yearStr;
	std::string mounthStr;
	std::string dayStr;
	int	mounth;
	int	day;

	yearStr = extractSubstring(s, '-');
	mounthStr = extractSubstring(s, '-');
	dayStr = s;
	if (yearStr.size() != 4 || mounthStr.size() != 2 || dayStr.size() != 2)
		return (0);
	if (yearStr.find_first_not_of(allowedChars) != std::string::npos ||
		mounthStr.find_first_not_of(allowedChars) != std::string::npos ||
		dayStr.find_first_not_of(allowedChars) != std::string::npos)
		return (0);
	mounth = myStof(mounthStr);
	day = myStof(dayStr);
	if (mounth == 0 || mounth > 12 || day == 0 || day > 31)
		return (0);
	return (1);
}

void	BitcoinExchange::testLine(const std::pair<std::string, std::string> &line) const
{
	float	value;

	if (!isDateValid(line.first))
		throw (InvalidDate());
	if (line.second.find('-') != std::string::npos)
		throw (NotPositiveNumber());
	if (line.second.find_first_not_of(".0123456789 \t") != std::string::npos)
		throw (InvalidNumber());
	if (line.second.empty())
		throw (MissingNumber());
	value = myStof(line.second);
	if (value > 1000)
		throw (TooLargeNumber());
}

std::pair<std::string, std::string>	BitcoinExchange::parseLine(std::string line, char delim) const
{
	std::pair<std::string, std::string> p;
	std::string date;
	std::string	value;

	date = myStringTrim(extractSubstring(line, delim), " \t");
	value = myStringTrim(extractSubstring(line, '\n'), " \t");
	p.first = date;
	p.second = value;
	return (p);
}

std::map<std::string, std::string> BitcoinExchange::parseFile(std::string filecontent, char delim)
{
	std::map<std::string, std::string> m;
	std::string	line;

	extractSubstring(filecontent, '\n');
	if (filecontent.find(delim) == std::string::npos)
		throw (DelimNotFound());
	line = extractSubstring(filecontent, '\n');
	while (!filecontent.empty() || !line.empty())
	{
		m.insert(parseLine(line, delim));
		line = extractSubstring(filecontent, '\n');
	}
	return (m);
}

void	BitcoinExchange::printResult(std::string &input) const
{
	std::pair<std::string, std::string>	parsedLine;
	std::string	line;
	
	line = extractSubstring(input, '\n');
	line = extractSubstring(input, '\n');
	while (!input.empty() || !line.empty())
	{
		if (!myStringTrim(line, " \t\n").empty())
		{
			try
			{
				parsedLine = parseLine(line, this->_delimInputFile);
				testLine(parsedLine);
				std::cout << parsedLine.first << " => " << parsedLine.second
					<< " = " << convert(parsedLine) << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cout << parsedLine.first << " => " << parsedLine.second
					<< " : ";
				std::cerr << e.what() << '\n';
			}
		}
		line = extractSubstring(input, '\n');
	}
}


/* ########## Exception ########## */

const char	*BitcoinExchange::CannotOpenFile::what(void) const throw()
{
	return ("Exception: Cannot open file");
}
const char	*BitcoinExchange::EmptyFile::what(void) const throw()
{
	return ("Exception: File is empty");
}
const char	*BitcoinExchange::DelimNotFound::what(void) const throw()
{
	return ("Exception: Delimiter is not found in the file");
}
const char	*BitcoinExchange::InvalidNumber::what(void) const throw()
{
	return ("Exception: Invalid number");
}
const char	*BitcoinExchange::MissingNumber::what(void) const throw()
{
	return ("Exception: Missing value");
}
const char	*BitcoinExchange::InvalidDate::what(void) const throw()
{
	return ("Exception: Invalid date");
}
const char	*BitcoinExchange::NotPositiveNumber::what(void) const throw()
{
	return ("Exception: Not a positive number");
}
const char	*BitcoinExchange::TooLargeNumber::what(void) const throw()
{
	return ("Exception: Too large number");
}


/* ########## Non-member function ########## */
