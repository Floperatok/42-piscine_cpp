
#include "Sed.hpp"

Sed::Sed(const char *fileName) : _inFile(fileName), _outFile(this->_inFile + ".replace")
{
}

Sed::~Sed(void)
{
}

void	Sed::replaceBy(std::string oldString, std::string newString)
{
	std::ifstream	inFile;
	std::ofstream	outFile;
	std::string		content;

	inFile.open(this->_inFile.c_str());
	outFile.open(this->_outFile.c_str());
	if (!inFile.is_open() || !outFile.is_open())
	{
		std::cerr << "Error: Cannot open file" << std::endl;
		inFile.close();
		outFile.close();
		exit(1);
	}
	
	std::getline(inFile, content, '\0');
	if (content.empty())
	{
		std::cerr << "Error: File's empty" << std::endl;
		inFile.close();
		outFile.close();
		exit(1);
	}
	inFile.close();
	
	for (int pos = content.find(oldString) ; pos != -1 ; pos = content.find(oldString))
	{
		content.erase(pos, oldString.length());
		content.insert(pos, newString);
	}

	outFile << content;
	outFile.close();
	std::cout << this->_outFile << " was created." << std::endl;
}
