#include <iostream>
#include <stack>
#include <iterator>
#include "includes/MutantStack.hpp"

int main() {

	MutantStack<int> mstack;
	mstack.push(2);
	mstack.push(21);
	std::cout << "size [" << mstack.size() << "]"<< std::endl;
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.push(1);
	mstack.push(11);
	mstack.push(224);
	mstack.push(31);

	std::cout << std::endl;
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	std::cout << "it: " << *it << std::endl;
	it++;
	std::cout << "it: " << *it << std::endl;
	it--;
	std::cout << "it: " << *it << std::endl;

	std::cout << "List: " << std::endl;
	while (it != ite) {
		std::cout << " " << *it << " " ;
		++it;
	}

	std::cout << std::endl;
	std::cout << "size [" << mstack.size() << "]"<< std::endl;
}
