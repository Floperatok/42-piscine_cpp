
#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact
{
private:
	std::string _first_name;
	std::string _last_name;
	std::string _nickname;
	std::string _phone_number;
	std::string _darkest_secret;
	int			_index;

public:
	Contact(void);
	~Contact(void);


	void	createContact(const int index);
	void	printContactList(void) const;
	void	printContactInfos(void) const;	
};

#endif