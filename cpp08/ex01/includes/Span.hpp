#pragma once
#include <iostream>
#include <vector>
#include <exception>

class IndexErrorException : public std::exception {
	public:
			const char* what() const throw() {
				return "Inapropriate usage of the vector: " ;
			}
};

class Span {

	public:
			Span();
			~Span();
			Span(size_t sizeMax);
			Span(const Span& src);
			Span& operator=(const Span& rhs);

			void	addNumber(int nbr);
			int		shortestSpan() const;
			int		longestSpan() const;
			int		begin() const;
			int		end() const;
	private:
			std::vector<int>	_vec;
			size_t				_sizeMax;
};
