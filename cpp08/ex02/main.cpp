#include <iostream>
#include <stack>
#include <iterator>
#include "includes/MutantStack.hpp"

int main() {

	MutantStack<int> mstack;
	mstack.push(2);
	mstack.push(21);
	std::cout << "size [" << mstack.size() << "]"<< std::endl;
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.top() << std::endl;
	mstack.push(1);
	mstack.push(11);
	mstack.push(224);
	mstack.push(31);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	it++;
	std::cout << *it << std::endl;
	it--;
	std::cout << *it << std::endl << std::endl;

	while (it != ite) {
		std::cout << *it << std::endl;
		++it;
	}
	std::cout << "size [" << mstack.size() << "]"<< std::endl;
	return 0;
}
