#include <iostream>
#include <iomanip>

template< typename T >
void swap(T& lhs, T& rhs) {
	T tmp = lhs;
	lhs = rhs;
	rhs = tmp;
}

template< typename T >
T&	min(T& lhs, T& rhs) {
	return lhs < rhs ? lhs : rhs;
}

template< typename T >
T& max(T& lhs, T& rhs) {
	return lhs > rhs ? lhs : rhs;
}