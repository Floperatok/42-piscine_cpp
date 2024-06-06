
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	{
		try
		{
			Form	randomForm;
			std::cout << randomForm << std::endl;
			Form	a38("A38", 0, 150);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}
	
	std::cout << "\n----------------\n" << std::endl;

	{
		try
		{
			Form	a38("A38", 150, 160);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}

	std::cout << "\n----------------\n" << std::endl;

	{
		try
		{
			Form	a38("A38", 70, 49);
			Form	copy;
			copy = a38;
			std::cout << copy << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << std::endl;;
		}
	}
	
	std::cout << "\n----------------\n" << std::endl;
	
	{
		try
		{
			Form		a38("A38", 149, 1);
			Bureaucrat	bob("bob", 150);
			bob.signForm(a38);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	std::cout << "\n----------------\n" << std::endl;

	{
		try
		{
			Form		a39("A39", 18, 1);
			Bureaucrat	albert("albert", 150);
			Bureaucrat	bob("bob", 18);
			albert.signForm(a39);
			bob.signForm(a39);
			bob.signForm(a39);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}

	return (0);
}