
#include "types.hpp"

Base	*generate(void)
{
	srand(time(0));

	switch (rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		return (0);
	}
}