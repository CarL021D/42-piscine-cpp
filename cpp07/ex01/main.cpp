#include "includes/Iter.hpp"
#include <iostream>
#include <iomanip>

int main() {

	int 		intArr[] = {1, 2, 3, 4, 5};
	double 		doubleArr[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::string stringArr[] = {"hello", "hola", "こんにちは"};

	iter(intArr, 5, printTArr<int>);
	iter(doubleArr, 5, printTArr<double>);
	iter(stringArr, 3, printTArr<std::string>);
}