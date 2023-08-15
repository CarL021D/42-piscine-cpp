#pragma once
#include <iostream>
#include <vector>
#include <exception>

class Span {
    class IndexErrorException : public std::exception {
        const char* what() const throw() {
            return "Exception: " ;
        }
    };

	public:
			Span();
			~Span();
			Span(size_t sizeMax);
			Span(const Span& src);
			Span& operator=(const Span& rhs);

            void    addNumber(int nbr);
            int    shortestSpan();
            int    longestSpan();
	private:
			std::vector<int>	_vec;
			size_t				_sizeMax;
};
