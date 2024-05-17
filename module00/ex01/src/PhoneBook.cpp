
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_index = 0;
}

PhoneBook::~PhoneBook(void)
{
}

void	PhoneBook::addContact(void)
{
	this->_contacts[this->_index].createContact(this->_index);
	_index = (_index + 1) % 8;
}

/*
 *	Reads the index from the user, ask the user to enter the index as long as
 *	the format isn't valid.
*/
static int	getIndexUserInput(void)
{
	std::string	input;
	bool		is_input_valid;
	int			index;

	do
	{
		std::cout << "Enter Index: ";
		std::getline(std::cin, input);
		is_input_valid = input.find_first_not_of("-0123456789") == std::string::npos; 
		if (!is_input_valid)
		{
			std::cout << "Error: Unrecognized character" << std::endl;
			continue ;
		}
		index = atoi(input.c_str());
		is_input_valid = index < 8 && index >= 0;
		if (!is_input_valid)
			std::cout << "Error: Index out of range" << std::endl;
	} while (input.empty() || !is_input_valid);
	return (index);
}

void	PhoneBook::search(void) const
{
	int	index;

	std::cout << "---------------------------------------------\n";
	std::cout << "|     INDEX|FIRST NAME| LAST NAME|  NICKNAME|\n";
	std::cout << "---------------------------------------------" << std::endl;
	for (int i = 0; i < 8; i++)
		this->_contacts[i].printContactList();
	std::cout << "--------------------------------------------" << std::endl;
	index = getIndexUserInput();
	this->_contacts[index].printContactInfos();
}

void	PhoneBook::getCommand(void)
{
	std::string	input;

	std::getline(std::cin, input);
	if (!input.compare("ADD"))
		this->addContact();
	else if (!input.compare("SEARCH"))
		this->search();
	else if (!input.compare("EXIT"))
		std::exit(EXIT_SUCCESS);
}
