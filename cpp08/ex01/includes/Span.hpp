#pragma once
#include <iostream>
#include <stdint.h>
#include <vector>
#include <climits>
#include <limits>
#include <cmath>
#include <exception>

class IndexErrorException : public std::exception {
	public:
			const char* what() const throw() {
				return "Inapropriate usage of the vector: " ;
			}
};

class Span {

	public:
			Span(int32_t sizeMax);
			~Span();
			Span(const Span& src);
			Span& operator=(const Span& rhs);

			void	addNumber(int32_t nbr);
			int		shortestSpan() const;
			int		longestSpan() const;
			int		begin() const;
			int		end() const;
			void	printContent() const;

			


	private:
			Span();
			
			std::vector<int32_t>	_vec;
			int32_t					_sizeMax;
			int32_t					_size;
};
