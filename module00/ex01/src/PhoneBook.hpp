
#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

# include "Contact.hpp"
# include <cstdlib>

class PhoneBook
{
private:
	Contact _contacts[8];
	int		_index;

	void	addContact(void);
	void	search(void) const;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void getCommand(void);
};

#endif