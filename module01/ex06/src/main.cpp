/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drenassi <@student.42perpignan.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 20:29:35 by drenassi          #+#    #+#             */
/*   Updated: 2024/04/05 21:01:14 by drenassi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void)
{
	Harl		harl;
	std::string	level;

	while (1)
	{
		std::cout << "Level: ";
		std::getline(std::cin, level);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (1);
		}
		if (level == "EXIT")
			return (0);
		else if (level != "DEBUG" && level != "INFO" && level != "WARNING" && level != "ERROR")
			std::cout << "This level doesn't exist. Enter EXIT to quit." << std::endl;
		else
			harl.complain(level);
	}
	return (0);
}
