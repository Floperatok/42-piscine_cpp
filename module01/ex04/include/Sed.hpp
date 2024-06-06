
#ifndef SED_HPP
# define SED_HPP

# include <cstdlib>
# include <iostream>
# include <fstream>

class	Sed
{
private:
	std::string	_inFile;
	std::string	_outFile;
public:
	Sed(const char *fileName);
	~Sed(void);

	void	replaceBy(std::string oldString, std::string newString);
};

#endif