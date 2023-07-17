#pragma once
#include <stdexcept>

template<typename T>
class Array {
	public:
			class OutOfRangeException : public std::exception {
				virtual const char* what() const throw();
			};
			Array();
			~Array();
			Array(ubnsigned int size);
			Array(const Array& src);
			Array& operator=(const Array& rhs);

			T&		operator[](unsigned int index);
			unsigned int size() const ;
	private:
			T*				_array;
			unsigned int	_size;
};