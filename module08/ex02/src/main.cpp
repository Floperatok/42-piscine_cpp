#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	printStack(MutantStack<int> &mstack)
{
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	printStackConst(const MutantStack<int> &const_mstack)
{
	MutantStack<int>::const_iterator it = const_mstack.begin();
	MutantStack<int>::const_iterator ite = const_mstack.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	printList(std::list<int> &list)
{
	std::list<int>::iterator it = list.begin();
	std::list<int>::iterator ite = list.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

void	printListConst(const std::list<int> &const_list)
{
	std::list<int>::const_iterator it = const_list.begin();
	std::list<int>::const_iterator ite = const_list.end();

	++it;
	--it;

	while (it != ite)
	{
		std::cout << *it << " ";
		it++;
	}
	std::cout << std::endl;
}

int main(void)
{
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		std::cout << "non-const:\t";
		printStack(mstack);
		std::cout << "const:\t\t";
		printStackConst(mstack);

		std::stack<int> s(mstack);
	}

	std::cout << std::endl;
	std::cout << "WITH LIST" << std::endl;
	std::cout << std::endl;

	{
		std::list<int> list;

		list.push_back(5);
		list.push_back(17);

		std::cout << list.back() << std::endl;

		list.pop_back();

		std::cout << list.size() << std::endl;
		
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);

		std::cout << "non-const:\t";
		printList(list);
		std::cout << "const:\t\t";
		printListConst(list);

		std::list<int> s(list);
	}
	return 0;
}
