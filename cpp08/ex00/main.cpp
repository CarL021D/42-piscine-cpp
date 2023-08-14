#include "includes/easyfind.hpp"
#include <vector>
#include <list>

int main() {
	try {
		std::vector<int> vec;
		vec.push_back(1);
		vec.push_back(2);
		vec.push_back(3);
		vec.push_back(4);
		easyFind(vec, 2);

		std::list<int> list;
		list.push_back(1);
		list.push_back(2);
		list.push_back(3);
		list.push_back(4);
		easyFind(list, 6);
	}
	catch (const NoOccurenceException &e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}