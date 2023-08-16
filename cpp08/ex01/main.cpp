#include <iostream>
#include <exception>
#include <vector>
#include <includes/Span.hpp>

int main()
{
	try {
		Span sp = Span(5);
		// Span sp = Span(0);
		sp.addNumber(100);
		sp.addNumber(6);
		sp.addNumber(0);
		int value1 = sp.begin() + 20;
		int value2	 = sp.end() - 20;
		sp.addNumber(value1);
		sp.addNumber(value2);
		// sp.addNumber(9);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

// - - - - - - - - - - - - - - - - - - - - - - - - - - -

	// 	Span sp = Span(10000);

    //     for (int i = 0; i < 10000; ++i) {
    //         int randomNumber = std::rand(); // Generates a random integer
    //         sp.addNumber(randomNumber);
    //     }
	// 	std::cout << sp.shortestSpan() << std::endl;
	// 	std::cout << sp.longestSpan() << std::endl;

	}
	catch (const IndexErrorException &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
