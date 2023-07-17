#include <iostream>

template< typename T >
void	printTArr(T& arg) {
	std::cout << " " << arg << " ";
}

template< typename T >
void	iter(T* arr, int size, void (*funcPtr)(T&)) {
	for (int i = 0; i < size; i++)
		(funcPtr)(arr[i]);
	std::cout << std::endl;
}
