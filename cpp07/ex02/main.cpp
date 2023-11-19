#include "includes/Array.hpp"
#include "includes/Array.tpp"
#include <iostream>
#include <stdexcept>

int main() {

	Array<int>			emptyArr;
	Array<std::string>	stringArr(3);
	Array<short>		shortArr(4);

	try {
		std::cout << "empty arr:" << std::endl;
		std::cout << "Arr size [" << emptyArr.size() << "]" << std::endl;
		std::cout << std::endl;

		std::cout << "std::string arr:" << std::endl;
		stringArr[0] = "こんにちは";
		stringArr[2] = "hola";
		std::cout << stringArr[0] << std::endl;
		std::cout << stringArr[1] << std::endl;
		std::cout << stringArr[2] << std::endl;
		std::cout << "Arr size [" << stringArr.size() << "]" << std::endl;
		std::cout << std::endl;

		std::cout << "operator = test" << std::endl;
		Array<std::string>	tmp = stringArr;
		std::cout << tmp[0] << std::endl;
		std::cout << "Arr size [" << tmp.size() << "]" << std::endl;
		std::cout << std::endl;

		std::cout << "cpy constructor test" << std::endl;
		Array<std::string>	cpy(stringArr);
		std::cout << cpy[2] << std::endl;
		std::cout << "Arr size [" << cpy.size() << "]" << std::endl;
		std::cout << std::endl;


		std::cout << "short arr:" << std::endl;
		shortArr[0] = 2;
		shortArr[1] = 4;
		shortArr[2] = 8;
		std::cout << shortArr[0] << std::endl;
		std::cout << shortArr[1] << std::endl;
		std::cout << shortArr[2] << std::endl;
		std::cout << "Arr size [" << shortArr.size() << "]" << std::endl;
		std::cout << std::endl;

		std::cout << "Arr size [" << cpy.size() << "]" << std::endl;
		std::cout << stringArr[3] << std::endl;
	} catch (const std::exception & e) {
		std::cout << "Exception of type: " << e.what() << std::endl;
	}
}