
#include "Contact.hpp"

Contact::Contact(void)
{
	this->_index = -1;
}

Contact::~Contact(void)
{
}

void	Contact::createContact(const int index)
{
	this->_index = index;
	do 
	{
		std::cout << "First name: ";
		getline(std::cin, this->_first_name);
	} while (this->_first_name.empty());
	do
	{
		std::cout << "Last name: ";
		getline(std::cin, this->_last_name);
	} while (this->_last_name.empty());
	do
	{
		std::cout << "Nickname: ";
		getline(std::cin, this->_nickname);
	} while (this->_nickname.empty());
	do
	{
		std::cout << "Phone number: ";
		getline(std::cin, this->_phone_number);
	} while (this->_phone_number.empty());
	do
	{
		std::cout << "Darkest secret: ";
		getline(std::cin, this->_darkest_secret);
	} while (this->_darkest_secret.empty());
}

static std::string	formatString(const std::string str)
{
	std::string	res = str;
	int 		str_size = str.size();

	if (str_size > 10) 
	{
		res.insert(9, ".");
		res = res.substr(0, 10);
	}
	else if (str_size < 10)
		for (int i = 0; i < 10 - str_size; i++) 
			res.insert(0, " ");
	return (res);
}

void	Contact::printContactList(void) const
{
	std::cout << "|";
	if (this->_index != -1)
		std::cout << "         " << this->_index;
	else
		std::cout << "          ";
	std::cout << "|";
	std::cout << formatString(this->_first_name);
	std::cout << "|";
	std::cout << formatString(this->_last_name);
	std::cout << "|";
	std::cout << formatString(this->_nickname);
	std::cout << "|" << std::endl;
}

void	Contact::printContactInfos(void) const
{
	if (this->_index == -1)
	{
		std::cout << "Error: Contact not found" << std::endl;
		return ;
	}
	std::cout << "Index:		" << this->_index << std::endl;
	std::cout << "First Name:	" << this->_first_name << std::endl;
	std::cout << "Last Name:	" << this->_last_name << std::endl;
	std::cout << "Nickname:	" << this->_nickname << std::endl;
	std::cout << "Phone Number:	" << this->_phone_number << std::endl;
	std::cout << "Darkest Secret:	" << this->_darkest_secret << std::endl;
}
