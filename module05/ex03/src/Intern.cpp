
#include "Intern.hpp"


/* ########## Constructor ########## */

Intern::Intern(void)
{
}

Intern::Intern(const Intern &copy)
{
	if (&copy != this)
		*this = copy;
}

Intern::~Intern(void)
{
}


/* ########## Operator overload ########## */

Intern &Intern::operator=(const Intern &other)
{
	if (&other != this)
	{
		
	}
	return (*this);
}


/* ########## Setter/Getter ########## */


/* ########## Member function ########## */

static AForm	*newShrubberyCreationForm(const std::string target);
static AForm	*newRobotomyRequestForm(const std::string target);
static AForm	*newPresidentialPardonForm(const std::string target);

AForm	*Intern::makeForm(const std::string formName, const std::string formTarget) const
{
	const int	nbTypes = 3;
	std::string	typesName[nbTypes] = {"PresidentialPardonForm", 
									"RobotomyRequestForm", 
									"ShrubberyCreationForm"};
	AForm *(*forms[3])(const std::string) = {&newShrubberyCreationForm, 
												&newRobotomyRequestForm, 
												&newPresidentialPardonForm};

	for (int i = 0; i < nbTypes; i++)
	{
		if (formName == typesName[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (forms[i](formTarget));

		}
	}
	throw (Intern::NotExistingForm());
	return (0);
}


/* ########## Exception ########## */

const char	*Intern::NotExistingForm::what(void) const throw()
{
	return ("Intern: Exception error: Not existing form");
}


/* ########## Non-member function ########## */

static AForm	*newShrubberyCreationForm(const std::string target)
{
	return (new ShrubberyCreationForm(target));
}

static AForm	*newRobotomyRequestForm(const std::string target)
{
	return (new RobotomyRequestForm(target));
}

static AForm	*newPresidentialPardonForm(const std::string target)
{
	return (new PresidentialPardonForm(target));
}
