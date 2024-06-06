
#include "Sed.hpp"

int	main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Usage: ./mySed filename s1 s2" << std::endl;
		exit(1);
	}
	
	Sed	sed(av[1]);
	sed.replaceBy(av[2], av[3]);
	return (0);
}
