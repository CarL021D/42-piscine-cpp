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


		// Span spo(10000);
		// spo.addRandomNbrs(10000);
		// // spo.printContent();
		// std::cout << "shortest span: " << spo.shortestSpan() << std::endl;
		// std::cout << "longest span: " << spo.longestSpan() << std::endl;
	}
	catch (const IndexErrorException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
}
