
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		ShrubberyCreationForm a;
		ShrubberyCreationForm b;
		a.setName("woaa");
		b = a;
		std::cout << b << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;;
	}
		
	std::cout << "\n-----------------\n" << std::endl;

	try
	{
		ShrubberyCreationForm	a("blueberry");
		Bureaucrat				bob("bob", 150);
		Bureaucrat				charles("charles", 140);
		Bureaucrat				superBob("superBob", 130);
	
		bob.signForm(a);
		bob.executeForm(a);
		charles.signForm(a);
		charles.executeForm(a);
		superBob.signForm(a);
		superBob.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		
	std::cout << "\n-----------------\n" << std::endl;
	
	try
	{
		RobotomyRequestForm		a("superCharles");
		Bureaucrat				bob("bob", 75);
		Bureaucrat				charles("charles", 60);
		Bureaucrat				superBob("superBob", 40);
	
		bob.signForm(a);
		bob.executeForm(a);
		charles.signForm(a);
		charles.executeForm(a);
		superBob.signForm(a);
		superBob.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "\n-----------------\n" << std::endl;
	
	try
	{
		PresidentialPardonForm	a("bob");
		Bureaucrat				bob("bob", 149);
		Bureaucrat				first_minister("first minister", 15);
		Bureaucrat				president("president", 4);
	
		bob.signForm(a);
		bob.executeForm(a);
		first_minister.signForm(a);
		first_minister.executeForm(a);
		president.signForm(a);
		president.executeForm(a);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}