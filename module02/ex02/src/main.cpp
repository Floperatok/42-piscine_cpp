#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
	{
		Fixed a;
		Fixed const b( Fixed(5.05f) * Fixed(2));
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		
		std::cout << b << std::endl;

		std::cout << Fixed::max( a, b ) << std::endl;
	}	
	std::cout << std::endl;
	{
		Fixed a(5);
		Fixed b(11);

		std::cout << "a + b = " << a + b << std::endl; 
		std::cout << "a - b = " << a - b << std::endl; 
		std::cout << "a * b = " << a * b << std::endl; 
		std::cout << "a / b = " << a / b << std::endl; 

		std::cout << "(a > b) = " << (a > b) << std::endl;
		std::cout << "(a < b) = " << (a < b) << std::endl;
		std::cout << "(Fixed(11) >= b) = " << (Fixed(11) >= b) << std::endl;
		std::cout << "(Fixed(11) <= b) = " << (Fixed(11) <= b) << std::endl;
		std::cout << "(Fixed(11) == b) = " << (Fixed(11) == b) << std::endl;
		std::cout << "(Fixed(11) != b) = " << (Fixed(11) != b) << std::endl;
	}
	return 0;
}