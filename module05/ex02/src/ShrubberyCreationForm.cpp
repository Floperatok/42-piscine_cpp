
#include "ShrubberyCreationForm.hpp"


/* ########## Constructor ########## */

ShrubberyCreationForm::ShrubberyCreationForm(void) \
	: AForm("ShrubberyCreationForm", 145, 137), _target("unknown")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) \
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}


/* ########## Operator overload ########## */

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
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

void	ShrubberyCreationForm::executeFormAction(void) const
{
	std::ofstream file;
	file.open((this->_target + "_shrubberry").c_str(), 
		std::ofstream::in | std::ofstream::trunc);
	file <<
		"               ,@@@@@@@,					\n"
		"       ,,,.   ,@@@@@@/@@,  .oo8888o.		\n"
		"    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o		\n"
		"   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'		\n"
		"   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'		\n"
		"   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'		\n"
		"   `&%\\ ` /%&'    |.|        \\ '|8'		\n"
		"       |o|        | |         | |			\n"
		"       |.|        | |         | |			\n"
		"    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_	\n";
	file.close();
	
}


/* ########## Exception ########## */


/* ########## Non-member function ########## */

