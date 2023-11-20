#include <iostream>
#include <cstdlib>
#include <exception>
#include <ctime>
#include <includes/Span.hpp>

int main()
{
	try {
		// // Empty arr test
		// Span spa = Span(0);
		// spa.addNumber(1);

		Span sp(5);
		sp.addNumber(100);
		sp.addNumber(3);
		sp.addNumber(0);
		sp.addNumber(21);
		sp.addNumber(44);
		sp.printContent();

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;
		std::cout << std::endl;


		Span spo(10000);
		for (uint32_t i = 0; i < 10000; ++i) {

			int32_t randomNumber = rand();
			spo.addNumber(randomNumber);
		}

		// spo.printContent();
		std::cout << "shortest span: " << spo.shortestSpan() << std::endl;
		std::cout << "longest span: " << spo.longestSpan() << std::endl;
	}
	catch (const IndexErrorException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
