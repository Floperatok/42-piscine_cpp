
#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void	Harl::debug(void)
{
	std::cout << "I love having extra ";
	std::cout << "bacon for my 7XL-double-cheese-triple-pickle-specialketchup ";
	std::cout << "burger. I really do!" << std::endl;
}

void	Harl::info(void)
{
	std::cout <<  "I cannot believe adding extra ";
	std::cout << "bacon costs more money. You didn't put enough bacon in my ";
	std::cout << "burger! If you did, I wouldn't be asking for more!" << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "I think I deserve to have some ";
	std::cout << "extra bacon for free. I've been coming for years whereas you ";
	std::cout << "started working here since last month." << std::endl;
}

void	Harl::error(void)
{
	std::cout << "This is unacceptable! I want ";
	std::cout << "to speak to the manager now." << std::endl;
}

void	Harl::complain(std::string level)
{
	void		(Harl::*functions[])() = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string	levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			i = 0;

	while (i < 4 && levels[i] != level)
		i++;
	if (i < 4)
		(this->*functions[i])();
}
