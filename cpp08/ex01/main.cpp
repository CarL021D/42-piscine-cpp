#include <iostream>
#include <exception>
#include <includes/Span.hpp>

int main()
{
	try {
		Span sp(5);
		// Span sp = Span(0);
		sp.addNumber(100);
		sp.addNumber(3);
		sp.addNumber(0);
		int value1 = sp.begin() + 20;
		int value2	 = sp.end() - 20;
		sp.addNumber(value1);
		sp.addNumber(value2);
		// sp.addNumber(9);
		sp.printContent();

		std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
		std::cout << "longest span: " << sp.longestSpan() << std::endl;

// - - - - - - - - - - - - - - - - - - - - - - - - - - -

		// Span spo(10000);

        // for (int i = 0; i < 10000; ++i) {
        //     int randomNumber = std::rand();
        //     spo.addNumber(randomNumber);
        // }

		// spo.printContent();
		// std::cout << "shortest span: " << spo.shortestSpan() << std::endl;
		// std::cout << "longest span: " << spo.longestSpan() << std::endl;

	}
	catch (const IndexErrorException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
