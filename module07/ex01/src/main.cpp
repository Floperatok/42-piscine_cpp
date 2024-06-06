
#include <cctype>
#include <iostream>
#include "iter.hpp"

void	myToupper(char &c)
{
	c = std::toupper(c);
}

void	half(int &i)
{
	i /= 2;
}

int main(void)
{
	char	text[10] = "salut toi";
	std::cout << text << std::endl;
	::iter(text, 10, &myToupper);
	std::cout << text << std::endl;

	std::cout << std::endl;

	int	numbers[5] = {42, 5, 99, 420, 20};
	for (int i = 0; i < 5; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	::iter(numbers, 5, &half);
	for (int i = 0; i < 5; i++)
	{
		std::cout << numbers[i] << " ";
	}
	std::cout << std::endl;
	return (0);
}