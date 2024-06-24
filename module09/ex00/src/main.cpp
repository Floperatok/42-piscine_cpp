
#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
	if (ac != 3)
	{
		std::cout << "Usage: ./btc [(string)filename] [(char)delimiter]" << std::endl;
		return (1);
	}
	BitcoinExchange(av[1], av[2][0]);
	return (0);
}
