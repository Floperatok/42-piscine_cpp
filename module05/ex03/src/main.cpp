
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
	try
	{
		Intern	a;
		AForm	*form;
		form = a.makeForm("ShrubberyCreationForm", "blueberry");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n--------------\n" << std::endl;
	
	try
	{
		Intern	a;
		AForm	*form;
		form = a.makeForm("RouteMakingForm", "paris");
		delete form;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}