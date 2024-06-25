
#include "PmergeMe.hpp"
#include <iostream>
#include <deque>
#include <vector>
#include <list>
#include <sys/time.h>



int main(int ac, char **av)
{
	if (ac < 2)
	{
		std::cout << "Usage: ./PmergeMe <n1 n2 n3 ...>" << std::endl;
		return (1);
	}

	try
	{
		// ####### LIST #######
		{
			PmergeMe<std::list<int> >	test(&av[1]);
			std::string typeName("std::list<int>");

			struct timeval	starttime;
			gettimeofday(&starttime, 0);
		
			test.load();
			std::cout << "Before:\t";
			test.print();
			test.sort();
			std::cout << "After:\t";
			test.print();

			struct timeval	endtime;
			gettimeofday(&endtime, 0);

			double	elapsedTime = (endtime.tv_sec - starttime.tv_sec) * 1000 
				+ (double)(endtime.tv_usec - starttime.tv_usec) / 1000;
			std::cout << "Time to process a range of " << test.getSize() 
				<< " elements with " << typeName
				<< " : " << elapsedTime << "ms" << std::endl;

		}
		std::cout << "------------------" << std::endl;
		// ####### VECTOR #######
		{
			PmergeMe<std::vector<int> >	test(&av[1]);
			std::string typeName("std::vector<int>");

			struct timeval	starttime;
			gettimeofday(&starttime, 0);
		
			test.load();
			std::cout << "Before:\t";
			test.print();
			test.sort();
			std::cout << "After:\t";
			test.print();

			struct timeval	endtime;
			gettimeofday(&endtime, 0);

			double	elapsedTime = (endtime.tv_sec - starttime.tv_sec) * 1000 
				+ (double)(endtime.tv_usec - starttime.tv_usec) / 1000;
			std::cout << "Time to process a range of " << test.getSize() 
				<< " elements with " << typeName
				<< " : " << elapsedTime << " ms" << std::endl;

		}
		std::cout << "------------------" << std::endl;
		// ####### DEQUE #######
		{
			PmergeMe<std::deque<int> >	test(&av[1]);
			std::string typeName("std::deque<int>");

			struct timeval	starttime;
			gettimeofday(&starttime, 0);
		
			test.load();
			std::cout << "Before:\t";
			test.print();
			test.sort();
			std::cout << "After:\t";
			test.print();

			struct timeval	endtime;
			gettimeofday(&endtime, 0);

			double	elapsedTime = (endtime.tv_sec - starttime.tv_sec) * 1000 
				+ (double)(endtime.tv_usec - starttime.tv_usec) / 1000;
			std::cout << "Time to process a range of " << test.getSize() 
				<< " elements with " << typeName
				<< " : " << elapsedTime << " ms" << std::endl;
		}
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	
	return (0);
}