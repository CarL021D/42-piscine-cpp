#include <iostream>
#include <stack>
#include <vector>
#include <iterator>
#include <stdint.h>
#include "includes/MutantStack.hpp"

int main() {

	MutantStack<int32_t> mstack;
	// MutantStack<int32_t, std::vector<int32_t> > mstack;
	mstack.push(2);
	mstack.push(21);
	std::cout << "MutantStack size: [" << mstack.size() << "]"<< std::endl;
	std::cout << "top: [" << mstack.top() << "]" << std::endl;
	mstack.pop();
	mstack.push(1);
	mstack.push(11);
	mstack.push(224);
	mstack.push(31);
	std::cout << "top: [" << mstack.top() << "]" << std::endl;
	std::cout << "MutantStack size: [" << mstack.size() << "]"<< std::endl;
	std::cout << std::endl;


	MutantStack<int32_t>::iter it = mstack.begin();
	// MutantStack<int32_t, std::vector<int32_t> >::iter it = mstack.begin();
	std::cout << "it: " << *it << std::endl;
	it++;
	std::cout << "it: " << *it << std::endl;
	it += 2;
	std::cout << "it: " << *it << std::endl;

	std::cout << "List: ";
	it = mstack.begin();
	MutantStack<int32_t>::iter ite = mstack.end();
	// MutantStack<int32_t, std::vector<int32_t> >::iter ite = mstack.end();
	while (it != ite) {
		std::cout << " [" << *it << "] " ;
		++it;
	}
	std::cout << std::endl; 
}
