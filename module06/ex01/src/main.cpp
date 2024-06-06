
# include "Serializer.hpp"
# include "Data.hpp"
# include <iostream>

int main(void)
{
	// Serializer a; // compilation error

	Data	*data = new Data("le correcteur est vraiment le plus beau");
	std::cout << "Data:\t" << data->getData() << std::endl;

	uintptr_t	raw = Serializer::serialize(data);
	std::cout << std::hex << "raw:\t0x" << raw << std::endl;

	// delete data; // segfault 

	Data	*data2 = Serializer::deserialize(raw);
	std::cout << "Data:\t" << data2->getData() << std::endl;

	delete data;
	return (0);
}