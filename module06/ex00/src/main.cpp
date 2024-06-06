
# include "ScalarConverter.hpp"
# include <string>

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: should take 1 argument" << std::endl;
		return (1);
	}
	ScalarConverter::convert(std::string(av[1]));

	// ScalarConverter a;
	return (0);
}