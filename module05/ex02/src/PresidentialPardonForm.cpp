
#include "PresidentialPardonForm.hpp"


/* ########## Constructor ########## */

PresidentialPardonForm::PresidentialPardonForm(void) \
	: AForm("PresidentialPardonForm", 25, 5), _target("unknown")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) \
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy)
{
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
}


/* ########## Operator overload ########## */

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (&other != this)
	{
		AForm::operator=(other);	
		this->_target = other._target;
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

void	PresidentialPardonForm::executeFormAction(void) const
{
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl; 
}


/* ########## Exception ########## */


/* ########## Non-member function ########## */

