#include <iostream>
#include <exception>
#include <vector>
#include <includes/Span.hpp>

int main()
{
	try {
		Span sp = Span(5);
		// Span sp = Span(0);
		sp << 6;
		sp << 129;
		sp.addNumber(2);
		sp.addNumber(17);
		sp.addNumber(34);
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
