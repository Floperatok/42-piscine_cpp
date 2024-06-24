
#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>

template<typename T>
bool	easyfind(const T container, const int toFind)
{
	if (std::find(container.begin(), container.end(), toFind) == container.end())	
		return (false);
	return (true);
}

#endif