
#include <Bureaucrat.hpp>

int main(void)
{
	try
	{
		Bureaucrat	bob("bob", 151);
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------" << std::endl;
	
	try
	{
		Bureaucrat	bob("bob", 0);
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-----------------" << std::endl;

	try
	{
		Bureaucrat	bob("bob", 150);
		bob.decrementGrade();
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	std::cout << "-----------------" << std::endl;

	try
	{
		Bureaucrat	bob("superbob", 1);
		bob.incrementGrade();
		std::cout << bob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------" << std::endl;

	try
	{
		Bureaucrat	noName;
		noName.setGrade(999);
		std::cout << noName << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "-----------------" << std::endl;

	try
	{
		Bureaucrat	bob("bob", 150);
		std::cout << bob << std::endl;
		bob.incrementGrade();
		bob.incrementGrade();
		bob.incrementGrade();
		std::cout << bob << std::endl;
		bob.decrementGrade();
		bob.decrementGrade();
		bob.decrementGrade();
		std::cout << bob << std::endl;
		bob.setGrade(1);
		std::cout << bob << std::endl;
		Bureaucrat	copyBob = bob;
		std::cout << copyBob << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}